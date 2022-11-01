#include<bits/stdc++.h>
using namespace std;
const int N = 14, M = 1<<N;
int n, m, x, y, a[N][N], g[M], cnt[M], pre[M][N][N];
pair<int,pair<int,int>> h[M];
bool f[M][N][N];
int main() {
	scanf("%d%d", &n, &m);
	while(m--) scanf("%d%d", &x, &y), --x, --y, a[x][y]=a[y][x]=1;
	for(int i=0; i<n; ++i) f[1<<i][i][i]=1;
	for(int i=0; i<1<<n; ++i) for(int u=0; u<n; ++u) for(int j=0; j<n; ++j) if(f[i][u][j])
		for(int k=0; k<n; ++k) if((!(i>>k&1) || (k==u && i!=((1<<u)|(1<<j)))) && a[j][k])
			f[i^(1<<k)][u][k]=1, pre[i^(1<<k)][u][k]=j;
	memset(g, 0x3f, sizeof g);
	g[1]=0, cnt[1]=1;
	for(int i=2; i<1<<n; ++i){
		cnt[i]=cnt[i>>1]+(i&1);
		for(int j=(i-1)&i; j; j=(j-1)&i) if(g[j]+cnt[i^j]+1<g[i])
			for(int x=0; x<n; ++x) if(j>>x&1)
				for(int y=x; y<n; ++y) if((j>>y&1) && f[i^j^(1<<x)^(1<<y)][x][y]){
					g[i]=g[j]+cnt[i^j]+1;
					h[i]=make_pair(i^j^(1<<x)^(1<<y), make_pair(x, y));
				}
	}
	int x=(1<<n)-1;
	printf("%d\n", g[x]);
	while(x>1){
		int s=h[x].first, a=h[x].second.first, b=h[x].second.second;
		x^=s^(1<<a)^(1<<b);
		do printf("%d %d\n", b+1, pre[s][a][b]+1), s^=1<<b, b=pre[s^(1<<b)][a][b]; while(a!=b);
	}
	return 0;
}