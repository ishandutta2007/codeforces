// @betaveros :: generated with cpp2.hs
#include <cstdio>
using namespace std;
int n, m;
char s[108][108];
int bad[108];
bool use[108];
int main() {
	scanf("%d", &n);
	scanf(" ");
	for (int i = 0; i < n; ++i){ fgets(s[i], 108, stdin); }
	for (int i = 0; i < n; ++i){ scanf("%d", &bad[i]); }
	bool ok = false;
	while (!ok) {
		ok = true;
		for (int i = 0; i < n; ++i){
			if (bad[i] == 0){
				use[i] = true;
				for (int j = 0; j < n; ++j){
					bad[j] -= s[i][j] - '0';
				}
				ok = false;
				break;
			}
		}
	}
	int c = 0;
	for (int i = 0; i < n; ++i){
		if (use[i]) { c++; }
	}
	printf("%d\n", c);
	bool fst = true;
	for (int i = 0; i < n; ++i){
		if (use[i]) {
			if (!fst) { printf(" "); }
			printf("%d", i + 1);
			fst = false;
		}
	}
	printf("\n");
}