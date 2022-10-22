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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int a[MAXN], b[MAXN], dfn[MAXN], dfnc, siz[MAXN];
int p[MAXN][21];
int s[2][MAXN];
vec<int> A[MAXN], B[MAXN];
vec<pair<int*, int>> stk;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x, int fa) {
	dfn[x] = ++dfnc, siz[x] = 1;
	for(int i = 0; i <= 20; ++i) p[x][i] = 0;
	p[x][0] = fa;
	for(int i = 1; i <= 20; ++i)
		p[x][i] = p[p[x][i - 1]][i - 1];
	for(auto to : B[x]) {
		DFS(to, x);
		siz[x] += siz[to];
	}
}

void make(int &x, int y) {
	stk.pb(mp(&x, x));
	x = y;
}

void Add(int id, int p, int v) {
	if(!p) return;
	for(; p <= n; p += lowbit(p)) make(s[id][p], s[id][p] + v);
}

int Ask(int id, int p) {
	int res = 0;
	for(; p; p -= lowbit(p)) res += s[id][p];
	return res;
}

void DFS2(int x, int fa, int now) {
	int top = stk.size();
	if(Ask(1, dfn[x]) == 1) {
		int y = x;
		for(int i = 20; ~i; --i) {
			if(!p[y][i]) continue;
			if(Ask(1, dfn[p[y][i]]) == 1) y = p[y][i];
		}
		Add(1, dfn[y], -1); Add(1, dfn[y] + siz[y], 1);
		Add(0, dfn[y], -1); now--;
	}
	if(Ask(0, dfn[x] + siz[x] - 1) - Ask(0, dfn[x] - 1) == 0) {
		Add(1, dfn[x], 1); Add(1, dfn[x] + siz[x], -1);
		Add(0, dfn[x], 1); now++;
	}
	Ans = max(Ans, now);
	for(auto to : A[x]) {
		if(to == fa) continue;
		DFS2(to, x, now);
	}
	while(stk.size() && stk.size() > top) {
		*(stk.back().fst) = stk.back().scd;
		stk.pop_back();
	}
}

void solve() {
	read(n); Ans = 0, dfnc = 0; stk.clear();
	for(int i = 1; i <= n; ++i)
		A[i].clear(), B[i].clear(), s[0][i] = s[1][i] = 0;
	for(int i = 2; i <= n; ++i) read(a[i]), A[a[i]].pb(i);
	for(int i = 2; i <= n; ++i) read(b[i]), B[b[i]].pb(i);
	DFS(1, 0);
	DFS2(1, 0, 0);
	printf("%d\n", Ans);
	while(stk.size()) {
		*(stk.back().fst) = stk.back().scd;
		stk.pop_back();
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	//Add(1, 2, 1);
	//cout << Ask(1, 1) << endl;
	//return 0;
	read(T);
	while(T--) solve();
	return 0;
}