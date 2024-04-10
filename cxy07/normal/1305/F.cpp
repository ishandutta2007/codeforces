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

const int MAXN = 2e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans = INF;
int a[MAXN], pr[MAXN], cnt;
bool np[MAXN];
unordered_set<int> S;
vec<int> fac;
mt19937 rnd(5224999);

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
		if(!np[i]) pr[++cnt] = i;
		for(int j = 1; j <= cnt && pr[j] * i <= siz; ++j) {
			np[pr[j] * i] = true;
			if(i % pr[j] == 0) break;
		}
	}
}

void Insert(int x) {
	if(!x) return;
	for(int i = 1; i <= cnt && pr[i] <= x; ++i) {
		if(x % pr[i]) continue;
		while(x % pr[i] == 0) x /= pr[i];
		if(!S.count(pr[i])) fac.pb(pr[i]), S.insert(pr[i]);
	} if((x ^ 1) && !S.count(x)) fac.pb(x), S.insert(x);
}

int calc(int x) {
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] < x) res += x - a[i];
		else res += min(a[i] % x, x - a[i] % x);
	} return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	sieve(2e6); read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	shuffle(a + 1, a + n + 1, rnd);
	for(int i = 1; i <= min(50ll, n); ++i)
		Insert(a[i]), Insert(a[i] - 1), Insert(a[i] + 1);
	for(auto x : fac) Ans = min(Ans, calc(x));
	printf("%lld\n", Ans);
	return 0;
}