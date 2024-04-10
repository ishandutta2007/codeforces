#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 55;
int n, num, h[N], siz[N], e[N<<1], pre[N<<1];
double g[N], C[N][N], f[N][N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u, int fa=0){
	memset(f[u], 0, sizeof f[u]), f[u][0]=siz[u]=1;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa){
		dfs(e[i], u), siz[u]+=siz[e[i]];
		memset(g, 0, sizeof g);
		for(int j=0; j<siz[e[i]]; ++j) g[j]=f[e[i]][j]*(siz[e[i]]-j);
		for(int j=1; j<=siz[e[i]]; ++j) for(int k=0; k<j; ++k) g[j]+=f[e[i]][k]/2;
		for(int j=siz[u]; j--;){
			// printf("[%.5lf]", g[j]);
			f[u][j]=f[u][j]*g[0]*C[siz[u]-1-j][siz[e[i]]];
			for(int k=1; k<=siz[e[i]]; ++k) f[u][j]+=f[u][j-k]*g[k]*C[siz[u]-1-j][siz[e[i]]-k]*C[j][k];
		}
		// puts("");
	}
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), add(x, y), add(y, x);
	C[0][0]=1;
	for(int i=1; i<=n; ++i) for(int j=0; j<=i; ++j) C[i][j]=(j?C[i-1][j-1]:0)+C[i-1][j];
	double k=1;
	for(int i=1; i<n; ++i) k/=i;
	for(int i=1; i<=n; ++i) dfs(i), printf("%.10lf\n", f[i][n-1]*k);
	return 0;
}