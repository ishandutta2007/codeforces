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
using Z = mod<int(1e9) + 7>;

const int N = 14;
int n;
Z a[N], win[N][1 << N], dp[1 << N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	FOR(i, n)
		cin >> a[i];

	FOR(i, n)
		FOR(mask, 1 << n) {
			win[i][mask] = 1;
			FOR(j, n)
				if (mask >> j & 1)
					win[i][mask] *= a[i] / (a[i] + a[j]);
		}

	Z res = 0;
	rep(mask, 1, 1 << n) {
		dp[mask] = 1;
		for (int s = ((mask - 1) & mask); s; s = ((s - 1) & mask)) {
			Z between = 1;
			FOR(i, n)
				if (s >> i & 1)
					between *= win[i][mask ^ s];
			dp[mask] -= dp[s] * between;
		}
		Z p = 1;
		FOR(i, n)
			if (mask >> i & 1)
				p *= win[i][((1 << n) - 1) ^ mask];
		res += Z(__builtin_popcount(mask)) * dp[mask] * p;
	}
	cout << res << '\n';

	return 0;
}