//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector
#define hash HASH

const int MAXN = 2.1e6 + 10;
const int INF = 2e9;
const ull base = 131;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Q, k;
int c[27], lens, lenq;
int dp[MAXN / 10][27], p2[MAXN], v[27];
ull hash[MAXN], p[MAXN], hash2[MAXN];
string s0, s, t, q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

ull val(int l, int r) {
	//assert(r < lens);
	if(!l) return hash[r];
	return hash[r] - hash[l - 1] * p[r - l + 1];
}

ull val2(int l, int r) {
	//assert(r < lenq);
	if(!l) return hash2[r];
	return hash2[r] - hash2[l - 1] * p[r - l + 1];
}

int calc(int p) {
	int res = 1;
	if(p) if(val(lens - p, lens - 1) != val2(0, p - 1)) res = 0;
	if(p < lenq - 1) if(val(0, lenq - p - 2) != val2(p + 1, lenq - 1)) res = 0;
	return res;
}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void solve() {
	s = s0;
	read(k); cin >> q;
	memset(c, 0, sizeof c);
	int now = 0, cnt = 0, res = 0;
	for(int i = 0; i < k; ++i) {
		if(s.length() >= q.length()) break;
		s = s + t[i] + s;
		now++;
	}
	lens = s.length(), lenq = q.length();
	hash[0] = s[0];
	for(int i = 1; i < lens; ++i)
		hash[i] = hash[i - 1] * base + s[i];
	hash[lens] = 0;
	hash2[0] = q[0];
	for(int i = 1; i < lenq; ++i)
		hash2[i] = hash2[i - 1] * base + q[i];
	hash2[lenq] = 0;
	for(int i = 0; i + lenq - 1 < lens; ++i)
		if(val(i, i + lenq - 1) == val2(0, lenq - 1)) cnt++;//inside
	for(int i = 0; i < lenq; ++i)
		c[q[i] - 'a'] += calc(i);
	(res += p2[k - now] % mod * cnt % mod) %= mod;
	for(int p = 0; p < 26; ++p) {
		v[p] = dp[k - 1][p];
		if(now && k - now >= 0) (v[p] += mod - (dp[now - 1][p] * p2[k - now] % mod)) %= mod;
	}
	if(k != now) {
		for(int p = 0; p < 26; ++p)
			(res += v[p] * c[p] % mod) %= mod;
	}
	printf("%lld\n", res);
}

signed main () {
#ifdef FILE
	freopen("G.in","r",stdin);
#endif
	read(n), read(Q);
	p[0] = p2[0] = 1;
	for(int i = 1; i <= (int)2e6; ++i) {
		p[i] = p[i - 1] * base;
		p2[i] = p2[i - 1] * 2 % mod;
	}
	cin >> s0 >> t;
	for(int i = 0; i < n; ++i) {
		for(int p = 0; p < 26; ++p) dp[i][p] = dp[i - 1][p] * 2 % mod;
		dp[i][t[i] - 'a']++;
	}
	while(Q--) solve();
	return 0;
}