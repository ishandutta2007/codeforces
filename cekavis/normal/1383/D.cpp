#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 252;
int n, m, r, b[N], c[N], a[N][N], X[N*N], Y[N*N], s[N][N];
bool f[N*N], g[N*N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
		scanf("%d", a[i]+j), b[i]=max(b[i], a[i][j]), c[j]=max(c[j], a[i][j]);
	for(int i=1; i<=n; ++i) f[b[i]]=1;
	for(int i=1; i<=m; ++i) g[c[i]]=1;
	for(int i=n*m, x=0, y=0, h=1; i; --i){
		x+=f[i], y+=g[i];
		if(f[i]||g[i]) s[x][y]=i; else s[X[h]][Y[h]]=i, ++h;
		if(f[i]) for(int j=y; --j;) X[++r]=x, Y[r]=j;
		if(g[i]) for(int j=x; --j;) X[++r]=j, Y[r]=y;
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) printf("%d%c", s[i][j], " \n"[j==m]);
	return 0;
}