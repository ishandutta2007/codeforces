#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn = 25;
int f[maxn][maxn][maxn], s[maxn][maxn], tmp[maxn][maxn], ans[maxn][maxn];
int n, m, a[maxn], b[maxn];

void mul(int a[maxn][maxn], int b[maxn][maxn]){
	memset(tmp, 0x3f, sizeof tmp);
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			for (int k=0; k<=n; k++)
				tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			a[i][j] = tmp[i][j];
}

signed main(){
	scanf("%I64d%I64d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%I64d", &a[i]);
	for (int i=1; i<=n; i++) scanf("%I64d", &b[i]);
	memset(f, 0x3f, sizeof f);
	for (int k=0; k<=n; k++){
		f[k][0][k] = 0;
		for (int i=0; i<n; i++)
			for (int j=0; j<=n; j++){
				f[k][i+1][j+1] = min(f[k][i+1][j+1], f[k][i][j] + a[i+1]);
				if (j) f[k][i+1][j-1] = min(f[k][i+1][j-1], f[k][i][j] + b[i+1]);
			}
	}
	memset(ans, 0x3f, sizeof ans);
	for (int i=0; i<=n; i++) ans[i][i] = 0;
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			s[i][j] = f[i][n][j];
	while (m){
		if (m&1) mul(ans, s);
		mul(s, s); m >>= 1;
	}
	printf("%I64d\n", ans[0][0]);
	return 0;
}