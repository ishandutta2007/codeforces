#include<bits/stdc++.h>
using namespace std;

const int maxn = 55, MOD = 51123987;
int f[maxn*3][maxn][maxn][maxn], link[maxn*3][3];
char s[maxn*3]; int n, ans;

void add(int &a, int b) {
	a = (a + b) % MOD;
}

int main() {
	scanf("%d%s", &n, s+1);
	link[n+1][0] = link[n+1][1] = link[n+1][2] = n+1;
	for (int i=n; i>=0; i--) {
		link[i][0] = link[i+1][0];
		link[i][1] = link[i+1][1];
		link[i][2] = link[i+1][2];
		if (i) link[i][s[i]-'a'] = i;
	}
	f[0][0][0][0] = 1;
	for (int i=0; i<=n; i++)
		for (int a=0; 3*a<=n+2; a++)
			for (int b=0; 3*b<=n+2; b++)
				for (int c=0; 3*c<=n+2; c++) {
					if (a+b+c == n && abs(a-b) <= 1 && abs(b-c) <= 1 && abs(c-a) <= 1) add(ans, f[i][a][b][c]);
					add(f[link[i][0]][a+1][b][c], f[i][a][b][c]);
					add(f[link[i][1]][a][b+1][c], f[i][a][b][c]);
					add(f[link[i][2]][a][b][c+1], f[i][a][b][c]);
				}
	printf("%d\n", ans);
	return 0;
}