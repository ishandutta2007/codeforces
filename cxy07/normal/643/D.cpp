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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q;
int sum[MAXN], cnt[MAXN], t[MAXN], fa[MAXN];
multiset<int> s[MAXN], S;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int cme(int x) {return t[x] - t[x] / (cnt[x] + 2) * (cnt[x] + 1);}
int cson(int x) {return t[x] / (cnt[x] + 2);}

void del(int x) {
	if(!s[x].size()) return;
	S.erase(S.find(*s[x].begin() + cson(x)));
	S.erase(S.find(*(--s[x].end()) + cson(x)));
}

void add(int x) {
	if(!s[x].size()) return;
	S.insert(*s[x].begin() + cson(x));
	S.insert(*(--s[x].end()) + cson(x));
}

void update(int x, int y) {
	static vec<int> tmp, idx, idx2; tmp.clear(), idx.clear(), idx2.clear();
	tmp.pb(x), tmp.pb(y), tmp.pb(fa[x]), tmp.pb(fa[fa[x]]), tmp.pb(fa[y]);
	for(auto x : tmp) if(x) idx.pb(x);
	idx2 = idx;
	for(auto x : idx) if(fa[x]) idx2.pb(fa[x]);
	sort(idx.begin(), idx.end()), sort(idx2.begin(), idx2.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	idx2.erase(unique(idx2.begin(), idx2.end()), idx2.end());
	for(auto x : idx2) del(x);
	for(auto x : idx) s[fa[x]].erase(s[fa[x]].find(sum[x]));
	for(auto x : idx) {
		sum[x] -= cme(x);
		for(auto y : idx) if(fa[y] == x) sum[x] -= cson(y);
	}
	cnt[fa[x]]--; fa[x] = y; cnt[fa[x]]++;
	for(auto x : idx) {
		sum[x] += cme(x);
		for(auto y : idx) if(fa[y] == x) sum[x] += cson(y);
	}
	for(auto x : idx) s[fa[x]].insert(sum[x]);
	for(auto x : idx2) add(x);
}

void solve() {
	int opt, x, y; read(opt);
	if(opt == 1) read(x), read(y), update(x, y);
	if(opt == 2) read(x), printf("%lld\n", sum[x] + cson(fa[x]));
	if(opt == 3) printf("%lld %lld\n", *S.begin(), *(--S.end()));
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q);
	for(int i = 1; i <= n; ++i) read(t[i]);
	for(int i = 1; i <= n; ++i) read(fa[i]), cnt[fa[i]]++;
	for(int i = 1; i <= n; ++i) sum[i] += cme(i), sum[fa[i]] += cson(i);
	for(int i = 1; i <= n; ++i) s[fa[i]].insert(sum[i]);
	for(int i = 1; i <= n; ++i) add(i);
	while(q--) solve();
	return 0;
}