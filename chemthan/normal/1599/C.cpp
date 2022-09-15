#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define rep_down(i, a, b) for (int i = (a), _b = (b); i > _b; --i)
#define debug(a) cerr << #a << ": " << (a) << '\n';
#define debug_arr(a, n) { cerr << #a << " "; rep(i, 0, n) cerr << a[i] << " \n"[i == n]; }
#define debug_two(a, b) cerr << #a << ": " << (a) << ", " << #b << ": " << (b) << '\n';

template <typename num_t>
inline void add_mod(num_t& a, const long long& b, const int& m) { a = (a + b) % m; if (a < 0) a += m; }
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) { return a < b ? a = b, true : false; }
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) { return a > b ? a = b, true : false; }
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) { return !lhs ? rhs : gcd(rhs % lhs, lhs); }
template <typename num_t>
num_t pw(num_t n, num_t k, num_t mod) {
	num_t res = 1; for (; k > 0; k >>= 1) { if (k & 1) res = 1ll * res * n % mod; n = 1ll * n * n % mod; } return res;
}

typedef long long ll;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const long long ll_inf = 3ll * inf * inf;
const int max_n = 1e5 + 7;

void solve() {
	int n;
	cin >> n;

	ll total = 1ll * n * (n - 1) * (n - 2) / 6;
	string prop; cin >> prop;

	int p = (prop[0] - '0');
	int dec = 1;
	rep(j, 1, sz(prop)) if (prop[j] != '.') {
		p = p * 10 + prop[j] - '0';
		dec *= 10;
	}
	debug_two(p, dec);

	ll needed = ceil(6.0 * total * p / dec);

	auto calc = [&](int m, int k) -> ll  {
		if (k == 0) return 1;
		if (k == 1) return m;
		if (k == 2) return 1ll * m * (m - 1) / 2;
		if (k == 3) return 1ll * m * (m - 1) * (m - 2) / 6;
		return 0;
	};

	for (int chose = 0; chose <= n; ++chose) {
		int remain = n - chose;

		ll cur_sum = calc(chose, 3) * 6 +
			calc(chose, 2) * calc(remain, 1) * 6 +
			calc(chose, 1) * calc(remain, 2) * 3;

		if (cur_sum >= needed) {
			cout << chose << '\n';
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	const bool multiple_test = false;
	int test = 1;
	if (multiple_test) cin >> test;

	for(int i = 0; i < test; ++i) {
//		printf("Case #%d: ", i + 1);
		solve();
	}
#ifdef _LOCAL_
	cerr << "\nruntime: " << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}