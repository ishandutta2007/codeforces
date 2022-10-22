//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 3e5 + 10;
const int INF = 2e16;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int a[MAXN], cnt[MAXN], idc, id2;
int ban[MAXN], c2[MAXN];
vec<int> bs[MAXN];
vec<pii> num[MAXN];
map<int, int> buk, id, tid;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n), read(m); Ans = 0;
	buk.clear(), id.clear(), tid.clear(), idc = 0, id2 = 0;
	for(int i = 1; i <= n; ++i) {
		bs[i].clear(), num[i].clear();
		cnt[i] = 0, ban[i] = 0, c2[i] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		read(a[i]), buk[a[i]]++;
		if(!tid.count(a[i])) tid[a[i]] = ++id2;
	}
	for(auto x : buk) {
		if(!id.count(x.scd)) { id[x.scd] = ++idc; c2[idc] = x.scd; }
		num[id[x.scd]].pb(mp(x.fst, tid[x.fst]));
	}
	for(int i = 1; i <= idc; ++i) sort(num[i].begin(), num[i].end());
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		if(!tid[x] || !tid[y]) continue;
		bs[tid[x]].pb(tid[y]); bs[tid[y]].pb(tid[x]);
	}
	for(int i = 1, v, p; i <= idc; ++i) {
		for(int _i = (int)num[i].size() - 1; ~_i; --_i) {
			v = num[i][_i].fst, p = num[i][_i].scd;
			ban[p] = true;
			for(auto q : bs[p]) ban[q] = true;
			for(int j = i; j >= 1; --j)
				for(int o = (int)num[j].size() - 1; ~o; --o) {
					if((num[j][o].fst + v) * (c2[i] + c2[j]) <= Ans) break;
					if(ban[num[j][o].scd]) continue;
					Ans = max(Ans, (num[j][o].fst + v) * (c2[i] + c2[j]));
					break;
				}
			ban[p] = false;
			for(auto q : bs[p]) ban[q] = false;
		}
	}
	cout << Ans << endl;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}