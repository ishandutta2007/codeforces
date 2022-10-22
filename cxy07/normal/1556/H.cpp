//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 3010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, m1, m, Ans = INF;
int d_lim[MAXN], X[MAXN], Y[MAXN], W[MAXN];
bool vis[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct M1 {
	int S;
	struct DSU {
		int f[MAXN];
		int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
		void unity(int x, int y) { (find(x) != find(y)) && (f[find(x)] = find(y)); }
		bool Init(int S) { 
			for(int i = 1; i <= n; ++i) f[i] = i; 
			for(int i = 1; i <= m1; ++i) {
				if(!((S >> (i - 1)) & 1)) continue;
				if(find(X[i]) != find(Y[i])) unity(X[i], Y[i]);
				else return false;
			}
			return true;
		}
	} ex[MAXN], tmp;
	void Init(int _S) { S = _S; }
	bool chk(int S) { return tmp.Init(S); }
	void build() {
		for(int i = m1 + 1; i <= m + 1; ++i) {
			if(!vis[i] && i <= m) continue;
			ex[i].Init(S);
			for(int j = m1 + 1; j <= m; ++j) {
				if(!vis[j] || i == j) continue;
				ex[i].unity(X[j], Y[j]);
			}
		}
	}
	bool valid(int x) { return ex[m + 1].find(X[x]) != ex[m + 1].find(Y[x]); }
	bool valid(int x, int y) { return (ex[x].find(X[y]) != ex[x].find(Y[y])); }
} M1;

struct M2 {
	int S, d[MAXN];
	void add(int S) {
		for(int i = 1; i <= n; ++i) d[i] = 0;
		for(int i = 1; i <= m1; ++i) if((S >> (i - 1)) & 1) d[X[i]]++, d[Y[i]]++;
	}
	bool chk(int S) {
		add(S);
		for(int i = 1; i <= k; ++i) if(d[i] > d_lim[i]) return false;
		return true;
	}
	void Init(int _S) { S = _S; }
	void build() {
		add(S);
		for(int i = m1 + 1; i <= m; ++i)
			if(vis[i]) d[X[i]]++, d[Y[i]]++;
	}
	bool valid(int x) {
		d[X[x]]++, d[Y[x]]++;
		bool res = (d[X[x]] <= d_lim[X[x]] && d[Y[x]] <= d_lim[Y[x]]);
		d[X[x]]--, d[Y[x]]--; return res;
	}
	bool valid(int x, int y) {
		d[X[x]]--, d[Y[x]]--, d[X[y]]++, d[Y[y]]++;
		bool res = (d[X[y]] <= d_lim[X[y]] && d[Y[y]] <= d_lim[Y[y]]);
		d[X[x]]++, d[Y[x]]++, d[X[y]]--, d[Y[y]]--; return res;
	}
} M2;

bool SPFA(int _s, int _t) {
	queue<int> Q;
	static int dis[MAXN], len[MAXN], pre[MAXN];
	static bool inq[MAXN];
	while(Q.size()) Q.pop();
	for(int i = m1 + 1; i <= m + 2; ++i)
		dis[i] = INF, len[i] = pre[i] = 0, inq[i] = false;
	dis[_s] = 0, inq[_s] = true; Q.push(_s);
	while(Q.size()) {
		int x = Q.front(); Q.pop(); inq[x] = false;
		for(auto to : G[x]) {
			int w = vis[to] ? -W[to] : W[to];
			if(dis[to] > dis[x] + w || (dis[to] == dis[x] + w && len[to] > len[x] + 1)) {
				dis[to] = dis[x] + w, len[to] = len[x] + 1, pre[to] = x;
				if(!inq[to]) Q.push(to), inq[to] = true;
			}
		}
	}
	if(dis[_t] == INF) return false;
	for(int x = pre[_t]; x != _s; x = pre[x]) vis[x] ^= 1;
	return true;
}

bool Augment() {
	M1.build(); M2.build(); int _s = m + 1, _t = m + 2;
	for(int i = m1 + 1; i <= m + 2; ++i) G[i].clear();
	for(int i = m1 + 1; i <= m; ++i) {
		if(vis[i]) continue;
		if(M1.valid(i)) G[_s].pb(i);
		if(M2.valid(i)) G[i].pb(_t);
	}
	for(int i = m1 + 1; i <= m; ++i) {
		if(!vis[i]) continue;
		for(int j = m1 + 1; j <= m; ++j) {
			if(vis[j]) continue;
			if(M1.valid(i, j)) G[i].pb(j);
			if(M2.valid(i, j)) G[j].pb(i);
		}
	}
	return SPFA(_s, _t);
}

int Matroid_Intersection(int S) {
	int res = 0, cnt = n - 1 - __builtin_popcount(S);
	memset(vis, false, sizeof vis);
	while(Augment()) cnt--;
	if(cnt) return INF;
	for(int i = 0; i < m1; ++i) if((S >> i) & 1) res += W[i + 1];
	for(int i = m1 + 1; i <= m; ++i) if(vis[i]) res += W[i];
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1; i <= k; ++i) read(d_lim[i]);
	for(int i = k + 1; i <= n; ++i) d_lim[i] = INF;
	m = (k - 1) * k >> 1;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			if(j > k) { read(W[++m]); X[m] = i, Y[m] = j; } 
			else { read(W[++m1]); X[m1] = i, Y[m1] = j; }
		}
	for(int S = 0; S < (1 << m1); ++S) {
		if(!M1.chk(S) || !M2.chk(S)) continue;
		M1.Init(S); M2.Init(S);
		Ans = min(Ans, Matroid_Intersection(S));
	}
	printf("%d\n", Ans);
	return 0;
}