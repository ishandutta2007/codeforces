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

const int MAXN = 2e5 + 10;
const int MAXB = 2010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct Query { int o, a, b; } qs[MAXN];

int n, q, B = 600;
int a[MAXN], p[MAXN], ip[MAXN];
int rep[MAXN], add[MAXN];
int idx[MAXN], idxc;
int sum[MAXB][MAXB], loc[MAXN], locc;
int tsum[MAXN], osum[MAXN];
bool vis[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void Add(int x, int v) {
	assert(rep[x] == x);
	for(; !vis[x]; x = rep[p[x]]) add[x] += v, vis[x] = true;
	for(; vis[x]; x = rep[p[x]]) vis[x] = false;
}

void clear() {
	for(int i = 1; i <= n; ++i)
		a[i] += add[rep[i]], tsum[i] = rep[i] = 0;
	for(int i = 1; i <= idxc; ++i)
		memset(sum[i], 0, sizeof(int) * (locc + 5));
	for(int i = 1; i <= idxc; ++i) add[idx[i]] = 0, idx[i] = 0;
	for(int i = 0; i <= n; ++i) loc[i] = 0;
	idxc = locc = 0;
}

signed main () {
#ifdef FILE
	freopen("CF1588F.in", "r", stdin);
	freopen("CF1588F.out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) read(p[i]), ip[p[i]] = i;
	read(q);
	for(int i = 1; i <= q; ++i)
		read(qs[i].o), read(qs[i].a), read(qs[i].b);
	for(int L = 1, R; L <= q; L += B) {
		R = min(q, L + B - 1);
		for(int i = L; i <= R; ++i) {
			if(qs[i].o == 1) {
				if(!loc[qs[i].a - 1]) loc[qs[i].a - 1] = ++locc;
				if(!loc[qs[i].b]) loc[qs[i].b] = ++locc;
			}
			if(qs[i].o >= 2) rep[qs[i].a] = qs[i].a;
			if(qs[i].o == 3) rep[qs[i].b] = qs[i].b;
		}
		for(int i = 1; i <= n; ++i) osum[i] = osum[i - 1] + a[i];
		for(int i = 1; i <= n; ++i) {
			if(rep[i] != i) continue;
			idx[++idxc] = i;
			for(int x = ip[i]; !rep[x]; x = ip[x]) rep[x] = i;
		}
		for(int i = 1; i <= n; ++i) {
			if(rep[i]) tsum[rep[i]]++;
			if(!loc[i]) continue;
			for(int j = 1; j <= idxc; ++j)
				sum[j][loc[i]] = tsum[idx[j]];
		} 
		for(int i = L, Ans, l, r; i <= R; ++i) {
			if(qs[i].o == 1) {
				l = qs[i].a, r = qs[i].b;
				Ans = osum[r] - osum[l - 1];
				for(int j = 1; j <= idxc; ++j)
					Ans += add[idx[j]] * (sum[j][loc[r]] - sum[j][loc[l - 1]]);
				printf("%lld\n", Ans);
			}
			if(qs[i].o == 2) Add(qs[i].a, qs[i].b);
			if(qs[i].o == 3) {
				swap(p[qs[i].a], p[qs[i].b]);
				ip[p[qs[i].a]] = qs[i].a;
				ip[p[qs[i].b]] = qs[i].b;
			}
		}
		clear();
	}
	return 0;
}