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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN << 1], to[MAXN << 1];
	inline void add(int x, int y) {
		nxt[++siz] = head[x];
		to[siz] = y, head[x] = siz;
	}
} e;

int n, m, cnt;
int ind[MAXN];
bool vis[MAXN << 1];
vec<int> tmp;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x) {
	for(int &i = e.head[x], to; i; i = e.nxt[i]) {
		if(vis[i]) continue;
		vis[i] = vis[i ^ 1] = true, to = e.to[i];
		DFS(to);
		if((++cnt) & 1) printf("%d %d\n", x, to);
		else printf("%d %d\n", to, x);
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m); e.siz = 1;
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		e.add(x, y), e.add(y, x);
		ind[x]++, ind[y]++;
	}
	for(int i = 1; i <= n; ++i) {
		if(ind[i] % 2 == 0) continue;
		tmp.pb(i);
	}
	for(int i = 0; i < tmp.size(); i += 2)
		m++, e.add(tmp[i], tmp[i + 1]), e.add(tmp[i + 1], tmp[i]);
	if(m & 1) m++, e.add(1, 1), e.add(1, 1);
	printf("%d\n", m);
	DFS(1);
	return 0;
}