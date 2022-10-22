//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

template<class T> 
T power(T x, long long e) {
	T res = 1;
	for (; e > 0; e /= 2) {
		if (e & 1)
			res = res * x;
		x = x * x;
	}
	return res;
}
template<int P>
struct mod {
	int x;
	mod(int v = 0) : x(v < 0 ? v + P : v) {}
	mod operator-() {
		return P - x;
	}
	mod inv() {
		assert(x != 0);
		return power(*this, P - 2);
	}
	void operator+= (mod o) {*this = *this + o;}
	void operator-= (mod o) {*this = *this - o;}
	void operator*= (mod o) {*this = *this * o;}
	void operator/= (mod o) {*this = *this * o.inv();}
	mod operator* (mod o) {return int(1ll * x * o.x % P);}
	mod operator/ (mod o) {return *this * o.inv();}
	mod operator+ (mod o) {return x + o.x < P ? x + o.x : x + o.x - P;}
	mod operator- (mod o) {return 0 <= x - o.x ? x - o.x : x - o.x + P;}
	friend ostream& operator<< (ostream &os, const mod &n) {
		return os << n.x;
	}
	friend istream& operator>> (istream &is, mod &n) {
		return is >> n.x;
	}
};
using Z = mod<998244353>;

const int N = 505;
int n, a[N];
Z dp[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	FOR(i, n) {
		string s;
		cin >> s;
		if (s == "+")
			cin >> a[i];
	}

	Z res = 0;
	FOR(i, n) {
		if (a[i] == 0)
			continue;
		Z x = 1;

		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		FOR(j, n) {
			if (i == j)
				continue;
			if (a[j] != 0 && ((j < i && a[j] > a[i]) || (i < j && a[j] >= a[i]))) {
				x *= 2;
			}
			else if (a[j] == 0) {
				rep(k, 0, n)
					if (k > 0 || j < i)
						dp[max(0, k - 1)] += dp[k];
			}
			else {
				per(k, 0, n) 
					dp[k + 1] += dp[k];
			}
		}

		res += x * Z(a[i]) * accumulate(dp, dp + n, Z(0));
	}

	cout << res << '\n';

	return 0;
}