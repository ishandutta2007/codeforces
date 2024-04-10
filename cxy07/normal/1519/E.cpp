//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 4e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN << 1], to[MAXN << 1], id[MAXN << 1];
	void add(int x, int y, int i) {
		nxt[++siz] = head[x];
		to[siz] = y, id[siz] = i;
		head[x] = siz;
	}
} e;

int n, m, idc;
int match[MAXN];
bool vis[MAXN], ban[MAXN << 1];
map<pii, int> id;
vec<pii> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int Gcd(int x, int y) {
	if(!y) return x;
	return Gcd(y, x % y);
}

int Getid(int x, int y) {
	int g = Gcd(x, y); x /= g, y /= g;
	if(id[mp(x, y)]) return id[mp(x, y)];
	return id[mp(x, y)] = ++idc;
}

void DFS(int x) {
	if(vis[x]) return;
	vis[x] = true;
	for(int &i = e.head[x], to; i; i = e.nxt[i]) {
		if(ban[i]) continue;
		to = e.to[i]; ban[i] = ban[i ^ 1] = true;
		if(!vis[to]) DFS(to);
		if(match[to]) {
			Ans.pb(mp(match[to], e.id[i]));
			match[to] = 0;
		} else if(match[x]) {
			Ans.pb(mp(match[x], e.id[i]));
			match[x] = 0;
		} else match[x] = e.id[i];
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); e.siz = 1;
	for(int i = 1, a, b, c, d, x, y; i <= n; ++i) {
		read(a), read(b), read(c), read(d);
		x = Getid((a + b) * d, c * b);
		y = Getid(a * d, (c + d) * b);
		e.add(x, y, i), e.add(y, x, i);
	}
	for(int i = 1; i <= idc; ++i)
		if(!vis[i]) DFS(i);
	printf("%ld\n", Ans.size());
	for(auto x : Ans) printf("%lld %lld\n", x.fst, x.scd);
	return 0;
}