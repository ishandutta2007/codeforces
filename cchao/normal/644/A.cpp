#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int res[110][110] = {{}};
	int dem = 1, rep = 2, remain = n;
	for(int i = 0; i < a; ++i) {
		for(int j = 0; j < b; ++j) {
			if((i + j) % 2 == 0) {
				if(dem <= n) {
					res[i][j] = dem;
					dem += 2;
					remain--;
				}
			}
			else {
				if(rep <= n) {
					res[i][j] = rep;
					rep += 2;
					remain--;
				}
			}
		}
	}
	if(remain > 0) {
		puts("-1");
	}
	else {
		for(int i = 0; i < a; ++i) {
			for(int j = 0; j < b; ++j) {
				printf("%d%c", res[i][j], " \n"[j == b - 1]);
			}
		}
	}
	return 0;
}