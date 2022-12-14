#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, M = 1e9 + 7, N = 14;

int inv(int i) {
	if(i == 1)
		return 1;
	return M - int(1LL * M / i * inv(M % i) % M);
}

int p[N][N], ip[N][N];
int dp[1 << N], pp[1 << N];

void add(int& a, int b) {
	a += b;
	if(a >= M)
		a -= M;
}

void mul(int& a, int b) {
	a = int(1LL * a * b % M);
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) if(i != j) {
			p[i][j] = int(1LL * a[i] * inv(a[i] + a[j]) % M);
			ip[i][j] = inv(p[i][j]);
		}		
	}

	int ans = 0;
	for(int mask = 1; mask < (1 << n); mask++) {
		dp[mask] = 1;
		vi subs;
		for(int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask)
			subs.PB(sub);
		reverse(ALL(subs));
		pp[0] = 1;
		for(int sub:subs) {
			debug(mask, sub);
			int k = __lg(sub);
			pp[sub] = pp[sub - (1 << k)];
			for(int i = 0; i < n; i++) if(i != k && (sub >> i & 1))
				mul(pp[sub], ip[i][k]);
			for(int i = 0; i < n; i++) if((mask >> i & 1) && !(sub >> i & 1))
				mul(pp[sub], p[k][i]);
			int tt = dp[sub];
			mul(tt, pp[sub]);
			add(dp[mask], M - tt);
		}
		int prob = dp[mask];
		for(int i = 0; i < n; i++) if(mask >> i & 1)
			for(int j = 0; j < n; j++) if(!(mask >> j & 1)) {
				mul(prob, p[i][j]);
			}
		mul(prob, __builtin_popcount(mask));
		add(ans, prob);
	}
	cout << ans << '\n';

}