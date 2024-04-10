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

int n, m, X[MAXN], Y[MAXN], W[MAXN];
int Ans[MAXN], id[MAXN], iid[MAXN];
int odd;
vec<pair<int*, int>> stk;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

struct DSU {
	int f[MAXN], siz[MAXN];
	int find(int x) { return f[x] == x ? x : find(f[x]); }
	void make(int &x, int y) { stk.pb(mp(&x, x)); x = y; }
	void unity(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		if(siz[x] < siz[y]) swap(x, y);
		if(siz[x] & 1) make(odd, odd - 1);
		if(siz[y] & 1) make(odd, odd - 1);
		make(f[y], x); make(siz[x], siz[x] + siz[y]);
		if(siz[x] & 1) make(odd, odd + 1);
	}
} S;

bool cmp(int x, int y) {return W[x] < W[y];}

void roll(int lim) {
	while(stk.size() > lim) {
		*(stk.back().fst) = stk.back().scd;
		stk.pop_back();
	}
}

void solve(int l, int r, int L, int R) {
	if(l > r) return;
	int mid = (l + r) >> 1, MID = R + 1, sav = stk.size();
	for(int i = l; i <= mid; ++i) 
		if(iid[i] < L) S.unity(X[i], Y[i]);
	for(int i = L; i <= R; ++i) {
		if(id[i] <= mid) S.unity(X[id[i]], Y[id[i]]);
		if(!odd) { Ans[mid] = i; break; }
	}
	roll(sav);
	if(!Ans[mid]) {
		for(int i = l; i <= mid; ++i)
			if(iid[i] < L) S.unity(X[i], Y[i]);
		solve(mid + 1, r, L, R); roll(sav);
		return;
	}
	for(int i = l; i <= mid; ++i)
		if(iid[i] < L) S.unity(X[i], Y[i]);
	solve(mid + 1, r, L, Ans[mid]); roll(sav);
	for(int i = L; i < Ans[mid]; ++i)
		if(id[i] < l) S.unity(X[id[i]], Y[id[i]]);
	solve(l, mid - 1, Ans[mid], R); roll(sav);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= m; ++i)
		read(X[i]), read(Y[i]), read(W[i]), id[i] = i;
	odd = n;
	for(int i = 1; i <= n; ++i) S.f[i] = i, S.siz[i] = 1;
	sort(id + 1, id + m + 1, cmp); 
	for(int i = 1; i <= m; ++i) iid[id[i]] = i;
	solve(1, m, 1, m); W[0] = -1;
	for(int i = 1; i <= m; ++i) printf("%d\n", W[id[Ans[i]]]);
	return 0;
}