#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair<LL, int> PLI;
typedef pair<int, LL> PIL;
typedef pair<LL, LL> PLL;
typedef double DB;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))
#define sqr(x) ((x)*(x))
#define bit(x) (1<<(x))
#define bitl(x) (1LL<<(x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))

template<typename T, typename U>
inline void chkmin(T &x, U y) {
	if (y < x) x = y;
}

template<typename T, typename U>
inline void chkmax(T &x, U y) {
	if (x < y) x = y;
}

const int MAXN = 111111;
int n;
LL a[MAXN];
int id[MAXN];
int rt[MAXN], l[MAXN], r[MAXN];
multiset<LL> S;
multiset<LL> :: iterator it;
int chk[MAXN];
LL sum[MAXN], ans[MAXN];

int Findroot(int u) {
	return rt[u] == u ? u : rt[u] = Findroot(rt[u]);
}

void make_root(int u, int v) {
	sum[v] += sum[u];
	rt[u] = v;
	l[v] = min(l[v], l[u]);
	r[v] = max(r[v], r[u]);
}

int main() {
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 0; i < n; i++) scanf("%d", id + i);
	for (int i = 1; i <= n; i++) rt[i] = i, l[i] = i, r[i] = i, sum[i] = a[i];
	//,,, sum[i] = a[i];
	for (int i = n - 1; i >= 0; i--) {
		if (!S.empty()) ans[i] = *(--S.end());
		int x = id[i];
		int y = x - 1;
		LL cnt = a[x];
		if (chk[y]) {
			int r = Findroot(y);
			it = S.lower_bound(sum[r]);
			cnt += *it;
			S.erase(it);
			make_root(r, x);
		}
		
		y = x + 1;
		if (chk[y]) {
			int r = Findroot(y);
			it = S.lower_bound(sum[r]);
			cnt += *it;
			S.erase(it);
			make_root(r, x);
		}
		S.insert(cnt);
		//cout << cnt << endl;
		chk[x] = 1;
	}
	for (int i = 0; i < n; i++) printf("%lld\n", ans[i]);
	return 0;
}