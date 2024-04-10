#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

template<class T> T power(T a, int64_t b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b & 1) {
			res *= a;
		}
	}
	return res;
}
template<int MOD> struct Mint {
	static_assert(MOD > 0, "MOD must be positive");
private:
	int v;
public:
	operator int() {
		return v;
	}
	Mint (int64_t x = 0) : v(x % MOD) {
		if (v < 0) {
			v += MOD;
		}
	}
	Mint& operator+= (const Mint& o) {
		v += o.v;
		if (v >= MOD) {
			v -= MOD;
		}
		return *this;
	}
	Mint& operator-= (const Mint& o) {
		v -= o.v;
		if (v < 0) {
			v += MOD;
		}
		return *this;
	}
	Mint& operator*= (const Mint& o) {
		v = (int64_t) v * o.v % MOD;
		return *this;
	}
	Mint& operator/= (const Mint& o) {
		v = (int64_t) v * int(power(o, MOD - 2)) % MOD;
		return *this;
	}
	friend Mint operator+ (Mint lhs, const Mint& rhs) { return lhs += rhs; }
	friend Mint operator- (Mint lhs, const Mint& rhs) { return lhs -= rhs; }
	friend Mint operator* (Mint lhs, const Mint& rhs) { return lhs *= rhs; }
	friend Mint operator/ (Mint lhs, const Mint& rhs) { return lhs /= rhs; }
	friend bool operator== (const Mint& lhs, const Mint& rhs) { return lhs.v == rhs.v; }
	friend bool operator!= (const Mint& lhs, const Mint& rhs) { return lhs.v != rhs.v; }
	friend std::ostream& operator<< (std::ostream& os, const Mint& num) { os << num.v; return os; }
	friend std::istream& operator>> (std::istream& is, Mint& num) { int64_t x; is >> x; num = Mint(x); return is; }
};
using Z = Mint<int(1e9 + 7)>;

const int N = 1 << 21;
int n;
Z dp[N], sum[N];

void solve() {
	cin >> n;

	if (n == 1) {
		cout << "1\n";
		return;
	}

	if (n == 2) {
		cout << "0\n";
		cout << "1\n";
		return;
	}

	dp[n + 1] = Z(0);
	sum[n + 1] = Z(0);
	dp[n] = Z(1);
	sum[n] = Z(1);

	per(i, 1, n - 1) {
		dp[i] = sum[i + 1] - sum[min(n, 2 * i - 1) + 1];
		if (2 * i - 1 >= n) {
			dp[i] += Z(1);
		}
		sum[i] = sum[i + 1] + dp[i];
	}

	Z div = power(Z(2), n);

	rep(i, 1, n) {
		Z L = power(Z(2), i / 2);
		Z R = dp[i];
		cout << L * R * (i == n ? Z(2) : Z(1)) / div << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}