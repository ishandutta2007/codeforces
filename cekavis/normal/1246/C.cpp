#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2005, P = 1000000007;
int n, m, d[N][N], r[N][N], f[N][N], g[N][N];
char s[N][N];
int main() {
	scanf("%d%d", &n, &m);
	if(n==1 && m==1) return puts("1"), 0;
	for(int i=1; i<=n; ++i) scanf("%s", s[i]+1);
	for(int i=n; i; --i) for(int j=m; j; --j)
		r[i][j]=r[i][j+1]+(s[i][j]=='R'),
		d[i][j]=d[i+1][j]+(s[i][j]=='R');
	f[1][1]=g[1][1]=1, f[2][1]=g[1][2]=P-1;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
		(g[i][j]+=g[i][j-1])%=P, (f[i][j]+=f[i-1][j])%=P;
		if(r[i][j+1]!=m-j)
			(g[i][j+1]+=f[i][j])%=P, (g[i][m-r[i][j+1]+1]+=P-f[i][j])%=P;
		if(d[i+1][j]!=n-i)
			(f[i+1][j]+=g[i][j])%=P, (f[n-d[i+1][j]+1][j]+=P-g[i][j])%=P;
	}
	printf("%d\n", (f[n][m]+g[n][m])%P);
	return 0;
}