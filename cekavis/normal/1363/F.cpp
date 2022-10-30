#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2005, C = 26;
int T, n, a[N][C], b[N][C], f[N][N];
char s[N], t[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%s%s", &n, s+1, t+1);
		for(int i=0; i<=n+1; ++i)
			memset(a[i], 0, C<<2), memset(b[i], 0, C<<2), memset(f[i], 0x3f, N<<2);
		for(int i=n; i; --i){
			memcpy(a[i], a[i+1], C<<2);
			memcpy(b[i], b[i+1], C<<2);
			++a[i][s[i]-='a'], ++b[i][t[i]-='a'];
		}
		for(int i=0; i<C; ++i) if(a[1][i]!=b[1][i]){
			puts("-1");
			goto nxt;
		}
		f[n+1][n+1]=0;
		for(int i=n+1; i; --i) for(int j=n+1; j; --j){
			if(j>1 && a[i][t[j-1]]>b[j][t[j-1]]) f[i][j-1]=min(f[i][j-1], f[i][j]);
			if(i>1) f[i-1][j]=min(f[i-1][j], f[i][j]+1);
			if(i>1 && j>1 && s[i-1]==t[j-1]) f[i-1][j-1]=min(f[i-1][j-1], f[i][j]);
		}
		printf("%d\n", f[1][1]);
		nxt:;
	}
	return 0;
}