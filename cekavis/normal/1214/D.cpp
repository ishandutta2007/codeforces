#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005, P = 998244853;
int n, m, *f[N], *g[N];
char *s[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) s[i]=new char[m+2];
	for(int i=0; i<=n+1; ++i) f[i]=new int[m+2], memset(f[i], 0, (m+2)<<2);
	for(int i=0; i<=n+1; ++i) g[i]=new int[m+2], memset(g[i], 0, (m+2)<<2);
	for(int i=1; i<=n; ++i) scanf("%s", s[i]+1);
	f[0][1]=1, g[n+1][m]=1;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(s[i][j]=='.')
		f[i][j]=(f[i-1][j]+f[i][j-1])%P;
	for(int i=n; i; --i) for(int j=m; j; --j) if(s[i][j]=='.')
		g[i][j]=(g[i+1][j]+g[i][j+1])%P;
	if(!f[n][m]) puts("0");
	else{
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
			if((i>1 || j>1) && (i<n || j<m) && (ll)f[i][j]*g[i][j]%P==f[n][m])
				return puts("1"), 0;
		puts("2");
	}
	return 0;
}