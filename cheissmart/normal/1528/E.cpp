#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 1e6 + 7, M = 998244353;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}
int ad(int a, int b) {
	return add(a, b), a;
}
int mu(int a, int b) {
	return int(1LL * a * b % M);
}
void mul(int& a, int b) {
	a = mu(a, b);
}
int inv(int a) {
	return a == 1 ? 1 : M - mu(M / a, inv(M % a));
}
int inv6 = inv(6);
int H2(int a) {
	return int(1LL * a * (a + 1) / 2 % M);
}
int H3(int n) {
	return mu(n + 2, mu(n + 1,  mu(n, inv6)));
}

int dp[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;

	dp[0] = 1;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		add(dp[i], dp[i - 1]);
		add(dp[i], mu(dp[i - 1], sum));
		add(dp[i], H2(dp[i - 1]));
		add(sum, dp[i - 1]);
	}
	int ans = dp[n];

	sum = 0;
	for(int i = 0; i <= n - 2; i++)
		add(sum, dp[i]);

	add(ans, mu(dp[n - 1], H2(sum)));
	add(ans, mu(H2(dp[n - 1]), sum));
	add(ans, H3(dp[n - 1]));

	add(ans, ans);
	add(ans, M - 1);
	for(int i = 1; i < n - 1; i++) {
		int a = ad(dp[i], M - dp[i - 1]);
		int b = ad(dp[n - 1 - i], M - 1);
		add(ans, mu(a, b));
	}

	cout << ans << '\n';

}