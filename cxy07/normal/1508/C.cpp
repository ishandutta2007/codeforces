//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 2e5 + 10;
const int SIZ = 1010;
const int INF = 2e17;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int x, y, w;
	void read() {cin >> x >> y >> w;}
	EDGE(int _x = 0, int _y = 0, int _w = 0) : x(_x), y(_y), w(_w) {}
	bool operator < (const EDGE &b) const {return w < b.w;}
} e[MAXN];

int n, m, v, kk, ans;
int f[MAXN];
bool vis[MAXN];
vec<pii> G[MAXN];
set<int> GG[MAXN], S;
set<int> :: iterator it;
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int find(int x) {
	if(f[x] != x) return f[x] = find(f[x]);
	return f[x];
}

void unity(int x, int y) {
	if(find(x) ^ find(y))
		f[find(x)] = find(y);
}

namespace brute {
	int Ans = INF, sum;
	int val[SIZ][SIZ], dis[SIZ];
	bool vis[SIZ];
	priority_queue<pii> Q;
	int prim() {
		int res = 0;
		for(int i = 1; i <= n; ++i) dis[i] = INF, vis[i] = false;
		dis[1] = 0; Q.push(mp(dis[1], 1));
		while(Q.size()) {
			int x = Q.top().scd, ww = Q.top().fst; Q.pop();
			if(vis[x]) continue;
			vis[x] = true; res -= ww;
			for(int i = 1; i <= n; ++i) {
				if(vis[i]) continue;
				if(dis[i] > val[x][i]) {
					dis[i] = val[x][i];
					Q.push(mp(-dis[i], i));
				}
			}
		}
		return res;
	}
	void main () {
		for(int i = 1; i <= n; ++i)
			for(auto to : G[i]) val[i][to.fst] = to.scd;
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j) {
				if(val[i][j]) continue;
				val[i][j] = val[j][i] = v;
				Ans = min(Ans, prim());
				val[i][j] = val[j][i] = 0;
			}
		printf("%lld\n", Ans);
	}
}

void BFS(int x) {
	Q.push(x); S.erase(x);
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		vis[x] = true;
		for(it = S.begin(); it != S.end();) {
			int to = *it++;
			if(GG[to].count(x) == 0) {
				S.erase(to), Q.push(to);
				vis[to] = true, unity(x, to);
			}
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n), read(m); kk = (n - 1) * n / 2 - m;
	for(int i = 1; i <= m; ++i) {
		e[i].read();
		GG[e[i].x].insert(e[i].y);
		GG[e[i].y].insert(e[i].x);
		G[e[i].x].pb(mp(e[i].y, e[i].w));
		G[e[i].y].pb(mp(e[i].x, e[i].w));
		v ^= e[i].w;
	}
	sort(e + 1, e + m + 1);
	if(kk < n) return brute :: main(), 0;
	for(int i = 1; i <= n; ++i) f[i] = i, S.insert(i);
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) BFS(i);
	for(int i = 1; i <= m; ++i) 
		if(find(e[i].x) != find(e[i].y))
			unity(e[i].x, e[i].y), ans += e[i].w;
	for(int i = 1; i <= n; ++i) 
		assert(find(1) == find(i));
	cout << ans << endl;
	return 0;
}