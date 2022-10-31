#include <cstdio>
using namespace std;

int main(){
	// hmm darn trigraphs.

	// ?: starting thing, move to end
	// ??: increment prev by 1
	for (int i = 0; i <= 8; i++) printf("%d??<>%d\n", i, i + 1);
	printf("9??>>??0\n");
	printf("??<>1\n");
	for (int i = 0; i <= 9; i++) printf("?%d>>%d?\n", i, i);
	printf("?>>??\n");
	printf(">>?\n");
}