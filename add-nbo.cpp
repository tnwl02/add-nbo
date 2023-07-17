#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <string.h> // for memset
#include <arpa/inet.h> // for htons

int main(int argc, char* argv[]) {
	uint32_t a, b;
	uint32_t a_net, b_net;
	int result;
	if(argc == 3)
	{
		memset(&a, 0, sizeof(a));
		memset(&b, 0, sizeof(b));
		FILE* first = fopen(argv[1], "rb");
		FILE* second = fopen(argv[2], "rb");
		fread(&a, sizeof(a), 1, first);
		fread(&b, sizeof(b), 1, second);
		//printf("%x\n", a);
		//printf("%x\n", b);
		a_net = ntohl(a);
		b_net = ntohl(b);
		//printf("%x\n", a_net);
		//printf("%x\n", b_net);
		result = int(a_net + b_net);
		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a_net, a_net, b_net, b_net, result, result);
	       	return 0;
	}
	else{
		printf("error");
		return 0;
	}
	return 0;
}
