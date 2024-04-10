#include <cstdio>
#define MOD 1000000007
#define MAXN 1005
int n, m, r[MAXN], c[MAXN], col[MAXN][MAXN], ans=1;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", r+i);
	for(int i=1; i<=m; ++i) scanf("%d", c+i);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=r[i]; ++j) col[i][j]=1;
		col[i][r[i]+1]=2;
	}
	for(int i=1; i<=m; ++i)
	{
		for(int j=1; j<=c[i]; ++j) if(col[j][i]==2) return puts("0"), 0; else col[j][i]=1;
		if(col[c[i]+1][i]==1) return puts("0"), 0;
		col[c[i]+1][i]=2;
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(!col[i][j]) ans=ans*2%MOD;
	printf("%d\n", ans);
	return 0;
}