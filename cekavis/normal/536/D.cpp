#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2005;
int n, m, s, t, xx, yy, a[N], c[N][N];
bool vis[N];
ll x[N], y[N], b[N][N], f[N][N][2];
pair<ll,int> w[N];
vector<pair<int,int>> e[N];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int work(int s, ll *d){
	memset(d+1, 0x3f, n<<3), memset(vis+1, 0, n);
	q.emplace(d[s]=0, s);
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto &i:e[u]) if(d[u]+i.second<d[i.first])
			q.emplace(d[i.first]=d[u]+i.second, i.first);
	}
	w[0].first=-1;
	for(int i=1; i<=n; ++i) w[i]=make_pair(d[i], i);
	sort(w+1, w+n+1);
	int id=0;
	for(int i=1; i<=n; ++i) d[w[i].second]=id+=(w[i].first!=w[i-1].first);
	return id;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1, x, y, z; i<=m; ++i)
		scanf("%d%d%d", &x, &y, &z),
		e[x].emplace_back(y, z), e[y].emplace_back(x, z);
	xx=work(s, x), yy=work(t, y);
	for(int i=1; i<=n; ++i) b[x[i]][y[i]]+=a[i], ++c[x[i]][y[i]];
	for(int i=xx; i; --i) for(int j=yy; j; --j)
		b[i][j]+=b[i+1][j], c[i][j]+=c[i+1][j];
	for(int i=xx; i; --i) for(int j=yy; j; --j)
		b[i][j]+=b[i][j+1], c[i][j]+=c[i][j+1];
	for(int i=xx+1; i; --i) for(int j=yy+(i<=xx); j; --j){
		if(c[i][j]-c[i+1][j])
			f[i][j][0]=b[i][j]-b[i+1][j]+max(f[i+1][j][0], -f[i+1][j][1]);
		else f[i][j][0]=f[i+1][j][0];
		if(c[i][j]-c[i][j+1])
			f[i][j][1]=b[i][j]-b[i][j+1]+max(f[i][j+1][1], -f[i][j+1][0]);
		else f[i][j][1]=f[i][j+1][1];
	}
	if(f[1][1][0]>0) puts("Break a heart");
	else puts(f[1][1][0]?"Cry":"Flowers");
	return 0;
}