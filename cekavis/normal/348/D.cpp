#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3005, P = 1000000007;
int n, m, a[3][3], f[N][N];
char s[N][N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%s", s[i]+1);
	f[1][2]=s[1][2]=='.';
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(s[i][j]=='.')
		(f[i][j]+=f[i-1][j]+f[i][j-1])%=P;
	a[1][1]=f[n-1][m], a[1][2]=f[n][m-1];
	memset(f, 0, sizeof f), f[2][1]=s[2][1]=='.';
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(s[i][j]=='.')
		(f[i][j]+=f[i-1][j]+f[i][j-1])%=P;
	a[2][1]=f[n-1][m], a[2][2]=f[n][m-1];
	printf("%lld\n", ((ll)a[1][1]*a[2][2]+(ll)(P-a[1][2])*a[2][1])%P);
	return 0;
}