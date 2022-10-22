//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 2e3 + 10;
const LL INF = 2e18;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,m,s,t;
int p[MAXN],c[MAXN][MAXN],pos[2][MAXN][MAXN],lim[2];
LL anss,anst,tot;
LL dp[2][MAXN][MAXN],sum[MAXN][MAXN],dis[2][MAXN];
bool vis[MAXN];
vector<int> v;
vector<pii> G[MAXN];
priority_queue<pair<LL,int> > Q;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int Getid(int x) {
	return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}

void Dijkstra(int s,LL *d,int &l) {
	memset(vis,0,sizeof vis);
	d[s] = 0;
	while(Q.size()) Q.pop();
	Q.push(mp(-d[s],s));
	while(Q.size()) {
		int x = Q.top().scd; Q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		for(int i = 0,to,w;i < G[x].size(); ++i) {
			to = G[x][i].fst,w = G[x][i].scd;
			if(d[to] > d[x] + w) {
				d[to] = d[x] + w;
				Q.push(mp(-d[to],to));
			}
		}
	}
	v.clear();
	for(int i = 1;i <= n; ++i) v.pb(d[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i = 1;i <= n; ++i) d[i] = Getid(d[i]);
	l = v.size();
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m); read(s); read(t);
	for(int i = 1;i <= n; ++i) read(p[i]);
	for(int i = 1,x,y,w;i <= m; ++i) {
		read(x); read(y); read(w);
		G[x].pb(mp(y,w));
		G[y].pb(mp(x,w));
	}
	for(int i = 1;i <= n; ++i) dis[0][i] = dis[1][i] = INF;
	Dijkstra(s,dis[1],lim[1]); Dijkstra(t,dis[0],lim[0]);
	for(int i = 1;i <= n; ++i) {
		tot += p[i];
		c[dis[1][i]][dis[0][i]]++;
		sum[dis[1][i]][dis[0][i]] += p[i];
	}
	for(int i = lim[1];i >= 1; --i) {
		for(int j = lim[0];j >= 1; --j) {
			sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
			pos[1][i][j] = min(i == lim[1] ? lim[1] : pos[1][i + 1][j],j == lim[0] ? lim[1] : pos[1][i][j + 1]);
			pos[0][i][j] = min(i == lim[1] ? lim[0] : pos[0][i + 1][j],j == lim[0] ? lim[0] : pos[0][i][j + 1]);
			if(c[i][j]) pos[1][i][j] = i,pos[0][i][j] = j;
			dp[1][i][j] = sum[i][j] - dp[0][pos[1][i][j] + 1][j];
			dp[0][i][j] = sum[i][j] - dp[1][i][pos[0][i][j] + 1];
			if(i == 1 && j == 1) break;
			dp[1][i][j] = min(dp[1][i][j],dp[1][i][j + 1]);
			dp[0][i][j] = min(dp[0][i][j],dp[0][i + 1][j]);
		}
	}
	anss = dp[1][1][1],anst = tot - dp[1][1][1];
	if(anss == anst) puts("Flowers");
	else if(anss < anst) puts("Cry");
	else puts("Break a heart");
	return 0;
}