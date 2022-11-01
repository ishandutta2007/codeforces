#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if(n > a * b) {
		printf("-1\n");
		return 0;
	}
	if(b % 2 == 1) {
		for(int i(0); i < a; i++) {
			for(int j(0); j < b; j++) {
				printf("%d%c", i * b + j + 1 <= n ? i * b + j + 1 : 0, j == b - 1 ? '\n' : ' ');
			}
		}
	}else {
		for(int i(0); i < a; i++) {
			for(int j(0); j < b; j++) {
				int idx(i % 2 == 0 ? i * b + j + 1 : i * b + (b - j - 1) + 1);
				printf("%d%c", idx <= n ? idx : 0, j == b - 1 ? '\n' : ' ');
			}
		}
	}
}