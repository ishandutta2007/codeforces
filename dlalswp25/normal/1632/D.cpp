#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int st[20][202020];

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) st[0][i] = A[i];
	for(int i = 1; i <= 19; i++) {
		for(int j = 1; j <= N; j++) {
			st[i][j] = gcd(st[i - 1][j], j > (1 << i - 1) ? st[i - 1][j - (1 << i - 1)] : 0);
		}
	}

	int lb = 0;
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		int p = i, g = A[i];
		while(p > lb) {
			int tmp = p;
			for(int j = 19; j >= 0; j--) {
				if(p - (1 << j) < lb) continue;
				if(st[j][p] % g) continue;
				p -= 1 << j;
			}
			if(i - tmp < g && g <= i - p) {
				ans++; lb = i; break;
			}
			if(p > lb) g = gcd(g, A[p]);
		}
		printf("%d ", ans);
	}
	puts("");
	return 0;
}