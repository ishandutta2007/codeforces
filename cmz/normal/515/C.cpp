#include <bits/stdc++.h>
using namespace std;
int n;
int bin[20], ans[20];
long long x;
int main() {
	scanf("%d", &n);
	scanf("%lld", &x);
	while (x) {
		int cur = x % 10;
		x = x / 10;
		for (int i = 2, now; i <= cur; ++i) {
			now = i;
			while (now % 2 == 0) {bin[2]++; now = now / 2;}
			while (now % 3 == 0) {bin[3]++; now = now / 3;}
			while (now % 5 == 0) {bin[5]++; now = now / 5;}
			while (now % 7 == 0) {bin[7]++; now = now / 7;}
		}
	}
	ans[7] = bin[7];
	for (int i = 1; i <= ans[7]; ++i) {
		bin[7]--; bin[5]--; bin[3] -= 2; bin[2] -= 4;
	}
	ans[5] = bin[5];
	for (int i = 1; i <= ans[5]; ++i) {
		bin[5]--; bin[3]--; bin[2] -= 3;
	}
	ans[3] = bin[3];
	for (int i = 1; i <= ans[3]; ++i) {
		bin[3]--; bin[2]--;
	}
	ans[2] = bin[2];
	for (int i = 1; i <= ans[7]; ++i) printf("7");
	for (int i = 1; i <= ans[5]; ++i) printf("5");
	for (int i = 1; i <= ans[3]; ++i) printf("3");
	for (int i = 1; i <= ans[2]; ++i) printf("2");
	return 0;
}