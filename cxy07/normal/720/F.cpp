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
const int INF = 9e18;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct info {
	int sum, cnt;
	info(int s = 0, int c = 0) : sum(s), cnt(c) {}
	bool operator < (const info &b) const { return (sum < b.sum) || (sum == b.sum && cnt < b.cnt); }
	bool operator > (const info &b) const { return (sum > b.sum) || (sum == b.sum && cnt > b.cnt); }
	bool operator == (const info &b) const { return sum == b.sum && cnt == b.cnt; }
	info operator + (const info &b) const { return info(sum + b.sum, cnt + b.cnt); }
} dp[MAXN], tmp[MAXN], mx[MAXN];

struct FenwickTree {
	int a[MAXN];
	void clear() { memset(a, 0, sizeof a); }
	void add(int x, int v) { for(; x < MAXN; x += lowbit(x)) a[x] += v; }
	int ask(int x) { int res = 0; { for(; x; x -= lowbit(x)) res += a[x]; } return res; }
} F1, F2;

int n, k, Ans = -INF;
int a[MAXN], sum[MAXN], sufmn[MAXN];
vec<pii> arr;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void add(int x, info v) { ++x; for(; x; x -= lowbit(x)) mx[x] = max(mx[x], v); }
info ask(int x) { ++x; info res(-INF, 0); { for(; x < MAXN; x += lowbit(x)) res = max(res, mx[x]); } return res; }

info chk(int g) {
	info res(0, 0); arr.clear(), F1.clear(), F2.clear();
	for(int i = 0; i < MAXN; ++i) mx[i] = dp[i] = tmp[i] = info(-INF, 0);
	for(int i = 1; i <= n; ++i) arr.pb(mp(sum[i - 1], -i)), arr.pb(mp(sum[i] - g, i));
	sort(arr.begin(), arr.end());
	for(auto x : arr) {
		if(x.scd < 0) F1.add(-x.scd, 1), F2.add(-x.scd, x.fst);
		else { int c = F1.ask(x.scd); res.cnt += c; res.sum += c * (sum[x.scd] - g) - F2.ask(x.scd); }
	}
	dp[0] = tmp[0] = info(0, 0); add(0, dp[0]);
	for(int i = 1, p; i <= n; ++i) {
		p = lower_bound(sufmn, sufmn + i, sum[i] - g, greater<int>()) - sufmn;
		if(p < i) assert(sum[i] - g - sum[p] >= 0);
		if(p) assert(sum[i] - g - sufmn[p - 1] < 0);
		dp[i] = ask(p);
		if(p) dp[i] = max(dp[i], info(tmp[p - 1].sum + sum[i] - g, tmp[p - 1].cnt + 1));
		add(i, dp[i]); sufmn[i] = min(sufmn[i - 1], sum[i]);
		tmp[i] = max(tmp[i - 1], info(dp[i].sum - sufmn[i], dp[i].cnt));
	}
	return res + dp[n];
}

signed main () {
#ifdef FILE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1; i <= n; ++i) read(a[i]), sum[i] = sum[i - 1] + a[i];
	int L = -5e9, R = 5e9, mid;
	while(L < R) { mid = (L + R + 1) >> 1; (chk(mid).cnt < k) ? R = mid - 1 : L = mid; }
	info cur = chk(L);
	Ans = max(Ans, cur.sum + k * L);
	printf("%lld\n", Ans);
	return 0;
}