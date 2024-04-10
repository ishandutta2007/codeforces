#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;

inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); int x = 0; }
	return op * x;
}

const int maxn = 300009;
int f[maxn][35], a[maxn], n, ans = 2e9;

void update(int &a, int b) {
	if (b < a) a = b;
}

int main() {
	n = read(); 
	rep (i, 1, n) {
		a[i] = read();
		a[i] /= 100;
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	rep (i, 0, n) rep (j, 0, 31) {
		if (j+a[i]/10 <= 31) 
			update(f[i+1][j+a[i+1]/10], f[i][j] + a[i+1]);
		if (j >= a[i+1]) 
			update(f[i+1][j-a[i+1]], f[i][j]);
		else
			update(f[i+1][0], f[i][j] + a[i+1]-j);
		//printf("%d %d %d\n", i, j, f[i][j]);
	}
	rep (i, 0, 31) update(ans, f[n][i]);
	printf("%d00\n", ans);
	return 0;
}