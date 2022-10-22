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

const int MAXN = 8e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN], to[MAXN], id[MAXN];
	void add(int x, int y, int i) {
		nxt[++siz] = head[x];
		to[siz] = y, id[siz] = i, head[x] = siz;
	}
} e;

int n, m, cnt;
int ind[MAXN], Ans[MAXN];
bool vis[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x) {
	for(int &i = e.head[x]; i; i = e.nxt[i]) {
		if(vis[i]) continue;
		vis[i] = vis[i ^ 1] = true;
		Ans[e.id[i]] = (x <= (int)2e5);
		DFS(e.to[i]);
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); e.siz = 1;
	for(int i = 1, x, y; i <= n; ++i) {
		read(x), read(y); y += (int)2e5;
		ind[x]++, ind[y]++;
		e.add(x, y, i), e.add(y, x, i);
	}
	for(int i = 1; i <= (int)4e5; ++i)
		if(ind[i] & 1) ind[i]++, ind[0]++, e.add(0, i, 0), e.add(i, 0, 0);
	for(int i = 1; i <= (int)2e5; ++i) DFS(i);
	for(int i = 1; i <= n; ++i)
		putchar(Ans[i] ? 'b' : 'r');
	return 0;
}