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

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int x, y, d;
	EDGE(int _x = 0, int _y = 0, int _d = 0) : x(_x), y(_y), d(_d) {}
	bool operator < (const EDGE &b) const {return d < b.d;}
} e[MAXN];

int n, m, Ans = INF;
int dis[MAXN];
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

struct M {
	bitset<MAXN> a[MAXN];
	void clear() {for(int i = 1; i <= n; ++i) a[i].reset();}
	M operator * (const M &b) const {
		static M res; res.clear();
		for(int i = 1; i <= n; ++i) res.a[i].reset();
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(a[i][j]) res.a[i] |= b.a[j];
		return res;
	}
	M operator ^ (const int &B) const {
		int b = B; static M res, base; res.clear(); base = (*this);
		for(int i = 1; i <= n; ++i) res.a[i][i] = 1;
		for(; b; b >>= 1, base = base * base) 
			if(b & 1) res = res * base;
		return res;
	}
} On, way;

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= m; ++i) 
		read(e[i].x), read(e[i].y), read(e[i].d);
	sort(e + 1, e + m + 1);
	On.a[1][1] = 1;
	for(int i = 1; i <= m; ++i) {
		On = On * (way ^ (e[i].d - e[i - 1].d));
		way.a[e[i].x][e[i].y] = 1;
		while(Q.size()) Q.pop();
		for(int p = 1; p <= n; ++p) dis[p] = -1;
		for(int p = 1; p <= n; ++p) if(On.a[1][p]) dis[p] = 0, Q.push(p);
		while(Q.size()) {
			int x = Q.front(); Q.pop();
			for(int p = 1; p <= n; ++p) {
				if(!way.a[x][p] || dis[p] != -1) continue;
				dis[p] = dis[x] + 1;
				Q.push(p);
			}
		}
		if(dis[n] != -1) Ans = min(Ans, dis[n] + e[i].d);
	}
	if(Ans == INF) puts("Impossible");
	else printf("%d\n", Ans);
	return 0;
}