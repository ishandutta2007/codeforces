#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n, a[N][N];
double dis[N], e[N], p[N];
bool vis[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d", a[i]+j);
	fill(dis, dis+n, 1e9);
	for(int i=1; i<=n; ++i){
		int u=0;
		for(int j=1; j<=n; ++j) if(!vis[j] && dis[j]<dis[u]) u=j;
		vis[u]=1;
		for(int j=1; j<=n; ++j) if(!vis[j] && a[j][u])
			e[j]+=dis[u]*(1-p[j])*a[j][u]*.01,
			p[j]+=(1-p[j])*a[j][u]*.01,
			dis[j]=(e[j]+1)/p[j];
	}
	printf("%.10lf\n", dis[1]);
	return 0;
}