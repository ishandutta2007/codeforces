//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct STAR {
	int center;
	vec<int> son;
};

int T, n, m;
int ind[MAXN], p[MAXN], q[MAXN];
bool ban[MAXN];
vec<STAR> s;
vec<int> lf;
set<int> G[MAXN], t[MAXN], nodes;
set<pii> info;
set<int> :: iterator it;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x) {
	nodes.erase(x);
	int at = 0;
	while(1) {
		it = nodes.upper_bound(at);
		if(it == nodes.end()) break;
		at = *it;
		if(G[x].find(at) != G[x].end()) continue;
		t[x].insert(at), t[at].insert(x);
		DFS(at);
	}
}

void solve() {
	read(n), read(m);
	int siz = n, sign = 0, og = n;
	for(int i = 1; i <= n; ++i) {
		G[i].clear(), t[i].clear();
		ind[i] = ban[i] = 0;
	}
	s.clear(); info.clear(), nodes.clear();
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		G[x].insert(y), G[y].insert(x);
		ind[x]++, ind[y]++;
	}
	for(int i = 1; i <= n; ++i)
		if(ind[i] == n - 1) nodes.insert(i);
	for(auto x : nodes) {
		ban[x] = true;
		ind[x] = 0;
		n--;
		for(auto to : G[x]) G[to].erase(x);
		G[x].clear();
		p[x] = q[x] = ++sign;
	}
	nodes.clear();
	n = siz;
	for(int i = 1; i <= n; ++i) {
		ind[i] = 0;
		if(!ban[i]) nodes.insert(i);
	}
	while(nodes.size()) DFS(*nodes.begin());
	nodes.clear();
	for(int i = 1; i <= n; ++i) 
		if(!ban[i]) ind[i] = t[i].size(), info.insert(mp(ind[i], i)), assert(ind[i]);
	while(info.size()) {
		int x = (*info.begin()).scd;
		int at = *t[x].begin();
		lf.clear();
		info.erase(mp(ind[at], at));
		for(auto to : t[at]) {
			info.erase(mp(ind[to], to));
			if(ind[to] == 1) lf.pb(to);
			else t[to].erase(at), info.insert(mp(--ind[to], to));
		}
		s.pb((STAR){at, lf});
	}
	int cntp = sign, cntq = sign;
	for(auto x : s) {
		p[x.center] = ++cntp;
		for(auto y : x.son) {
			p[y] = ++cntp;
			q[y] = ++cntq;
		}
		q[x.center] = ++cntq;
	}
	for(int i = 1; i <= og; ++i) printf("%d%c", p[i], " \n"[i == og]);
	for(int i = 1; i <= og; ++i) printf("%d%c", q[i], " \n"[i == og]);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}