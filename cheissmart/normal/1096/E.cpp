#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 998244353, N = 1e5 + 7;

int f[N], inv[N], fi[N];

int INV(int i) {
	if(i == 1) return 1;
	return M - (ll) M / i * INV(M % i) % M;
}

int C(int n, int k) {
	return (ll) f[n] * fi[k] % M * fi[n - k] % M;
}

int H(int n, int k) {
	if(n == 0) return k == 0;
	return C(n + k - 1, k);
}

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;

	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (ll) f[i - 1] * i % M;
	inv[1] = 1;
	for(int i = 2; i < N; i++) inv[i] = M - (ll) M / i * inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++) fi[i] = (ll) fi[i - 1] * inv[i] % M;

	int p, s, r;
	cin >> p >> s >> r;
	if(p == 1) return cout << 1 << endl, 0;
	auto go = [&](int score, int cnt, int sum) {
		if(cnt == 0) return sum ? 0 : 1;
		if(score == 0) return cnt ? 0 : 1;
		int ans = 0;
		for(int illegal = 0; illegal <= cnt; illegal++) {
			int ways = C(cnt, illegal);
			int rem_sum = sum - score * illegal;
			if(rem_sum < 0) continue;
			ways = (ll) ways * H(cnt, rem_sum) % M;
			if(illegal & 1) ways = M - ways;
			add(ans, ways);
		}
		return ans;
	};
	int yes = 0, all = 0;
	for(int score = r; score <= s; score++) {
		int tot_ways = H(p - 1, s - score);
		add(all, tot_ways);
		for(int same = 0; same <= p - 1; same++) {
			int rem_sum = s - (same + 1) * score, rem_cnt = p - 1 - same;
			if(rem_sum < 0) continue;
			int ways = (ll) go(score, rem_cnt, rem_sum) * C(p - 1, same) % M;
			ways = (ll) ways * inv[same + 1] % M;
			add(yes, ways);
		}
	}
	int ans = (ll) yes * INV(all) % M;
	cout << ans << endl;

}