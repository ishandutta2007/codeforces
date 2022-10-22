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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, idc, Ans;
int a[MAXN], lim[MAXN], tmp[MAXN];
int pos[MAXN], to[MAXN], to2[MAXN];
map<int, int> _id;
pii s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n), read(m); Ans = INF;
	_id.clear(), idc = 0; lim[n + 1] = INF;
	for(int i = 1; i <= n; ++i) {
		read(a[i]); lim[i] = INF;
		if(!_id.count(a[i])) _id[a[i]] = ++idc;
		a[i] = _id[a[i]]; pos[i] = 0;
	}
	for(int i = 1; i <= m; ++i) read(s[i].fst), read(s[i].scd);
	sort(s + 1, s + m + 1, [&](auto a, auto b) { return a.scd > b.scd; });
	for(int i = n, p = 1, L = n + 1, o = n; i >= 1; --i) {
		while(p <= m && s[p].scd >= i) L = min(L, s[p++].fst);
		while(o >= L) { pos[a[o]] = o; --o; }
		if(L > i) continue;
		assert(pos[a[i]]); lim[i] = pos[a[i]];
	}
	for(int i = n; i >= 1; --i) lim[i] = min(lim[i], lim[i + 1]);
	for(int i = 1; i <= n; ++i) pos[i] = 0;
	pos[a[1]] = 1;
	for(int l = 1, r = 1; l <= n; ++l) {
		while(r < n && !pos[a[r + 1]]) pos[a[++r]] = 1;
		to[l] = r + 1; pos[a[l]] = 0;
	}
	for(int i = 1; i <= n; ++i) pos[i] = 0;
	pos[a[n]] = 1;
	for(int r = n, l = n; r >= 1; --r) {
		while(l > 1 && !pos[a[l - 1]]) pos[a[--l]] = 1;
		to2[r] = l - 1; pos[a[r]] = 0;
	}
	reverse(s + 1, s + m + 1);
	int st = 1;
	for(int i = 1; i <= m; ++i)
		if(to2[s[i].scd] >= s[i].fst)
			st = max(st, to2[s[i].scd]);
	int num = INF;
	for(int i = 1; i <= m; ++i)
		if(to[s[i].fst] <= s[i].scd)
			num = min(num, to[s[i].fst]);
	for(int i = st, L, mn = INF, p = 1; i <= n; ++i) {
		L = lim[i + 1];
		/*if(i - min(L, mn) + 1 == 1) {
			cerr << i << endl;
		}*/
		Ans = min(Ans, i - min(L, min(mn, num)) + 1);
	}
	printf("%d\n", max(Ans, 0));
}

signed main () {
#ifdef FILE
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}