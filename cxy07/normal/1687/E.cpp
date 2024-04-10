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

const int MAXN = 1e5 + 10;
const int SIZ = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, g = 1, v;
int pr[SIZ], pcnt, a[MAXN];
int idx[MAXN], cnt[SIZ], pid[SIZ];
bool np[SIZ], vis[MAXN];
vec<int> prs, cur;
vec<pii> fact[MAXN], id[20];
vec<vec<int>> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void sieve(int siz) {
	for(int i = 2; i <= siz; ++i) {
		if(!np[i]) { pr[++pcnt] = i; pid[i] = pcnt; }
		for(int j = 1; j <= pcnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}

signed main () {
#ifdef FILE
	freopen("CF1687E.in", "r", stdin);
	freopen("CF1687E.out", "w", stdout);
#endif
	read(n); sieve(1e6);
	for(int i = 1, x, c; i <= n; ++i) {
		read(x); a[i] = x;
		for(int j = 1; j <= pcnt && pr[j] * pr[j] <= x; ++j) {
			if(x % pr[j]) continue;
			c = 0; while(x % pr[j] == 0) x /= pr[j], ++c;
			fact[i].pb(mp(pr[j], c)); ++cnt[j];
		}
		if(x > 1) fact[i].pb(mp(x, 1)), ++cnt[pid[x]];
	}
	for(int i = 1; i <= pcnt; ++i) 
		if(cnt[i] > n - 2) prs.pb(pr[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < (int)prs.size(); ++j) {
			bool flag = false;
			for(auto p : fact[i]) 
				if(p.fst == prs[j]) { id[j].pb(mp(p.scd, i)); flag = true; }
			if(!flag) id[j].pb(mp(0, i));
		}
	for(int i = 0; i < (int)prs.size(); ++i) {
		sort(id[i].begin(), id[i].end());
		vis[id[i][0].scd] = vis[id[i][1].scd] = true;
		for(int j = 1; j <= id[i][0].fst + id[i][1].fst; ++j) g *= prs[i];
	}
	for(int i = 1; i <= n; ++i) if(vis[i]) idx[++m] = i;
	for(int i = 1; i <= m; ++i) 
		for(int j = i + 1; j <= m; ++j) 
			v = __gcd(a[idx[i]] * a[idx[j]], v);
	v /= g; if(!v) v = 1;
	for(int i = 1, c = 0; i <= pcnt; ++i) {
		if(v % pr[i]) continue;
		c = 0; /*cerr << pr[i] << endl;*/
		for(int j = 1; j <= n && c < 2; ++j)
			if(a[j] % pr[i] && vis[j]) ++c;
		for(int j = 1; j <= n && c < 2; ++j)
			if(a[j] % pr[i] && !vis[j]) { vis[j] = true; ++c; }
		assert(c == 2);
	}
	m = 0;
	for(int i = 1; i <= n; ++i) if(vis[i]) idx[++m] = i;
	for(int S = 1, coef; S < (1 << m); ++S) {
		cur.clear(); coef = (popc(S) - 2) * ((popc(S) & 1) ? -1 : 1);
		if(coef < 0) cur.pb(1), coef = -coef;
		else cur.pb(0);
		for(int i = 1; i <= m; ++i)
			if((S >> (i - 1)) & 1) cur.pb(idx[i]);
		while(coef--) Ans.pb(cur);
	}
	printf("%ld\n", Ans.size());
	for(auto x : Ans) {
		printf("%lld %lld ", x[0], (int)x.size() - 1);
		for(int i = 1; i < (int)x.size(); ++i) printf("%lld ", x[i]);
		putchar('\n');
	}
	return 0;
}