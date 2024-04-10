//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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
#define y1 _y1

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
		//cerr << x << ' ' << y << endl;
		nxt[++siz] = head[x];
		to[siz] = y, id[siz] = i, head[x] = siz;
	}
} e;

int n, m, tot, cnt;
int L[MAXN], R[MAXN], ind[MAXN];
bool vis[MAXN], opt[MAXN];
vec<int> v;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x) {
	for(int &i = e.head[x], to, id; i; i = e.nxt[i]) {
		if(vis[i]) continue;
		to = e.to[i], id = e.id[i]; vis[i] = vis[i ^ 1] = true;
		DFS(to); opt[abs(id)] = (id < 0);
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); e.siz = 1; cnt = n;
	for(int i = 1; i <= n; ++i) { read(L[i]), read(R[i]); v.pb(L[i]), v.pb(R[i] + 1); }
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	tot = v.size();
	for(int i = 1, a, b; i <= n; ++i) {
		a = lower_bound(v.begin(), v.end(), L[i]) - v.begin() + 1;
		b = lower_bound(v.begin(), v.end(), R[i] + 1) - v.begin() + 1;
		ind[a]++, ind[b]++, e.add(a, b, i), e.add(b, a, -i);
	}
	for(int i = 1, pre = -1; i <= tot; ++i) {
		if((ind[i] & 1) == 0) continue;
		if(~pre) {
			++ind[pre], ++ind[i], ++cnt;
			e.add(i, pre, cnt), e.add(pre, i, -cnt); pre = -1;
		} else pre = i;
	}
	for(int i = 1; i <= tot; ++i) DFS(i);
	for(int i = 1; i <= n; ++i) printf("%d ", opt[i]);
	return 0;
}