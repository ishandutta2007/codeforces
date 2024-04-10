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
int P;
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
using Z = mod;

const int M = 500 * 500;
const int D = 2 * M + 1;

int n;
Z f[D];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> P;

	Z pref = 1;
	per(i, 1, n + 1) {
		rep(j, 1, D)
			f[j] += f[j - 1];

		per(j, i, D)
			f[j] -= f[j - i];

		per(j, 0, D - 1)
			f[j] += f[j + 1];

		rep(j, 0, D - i)
			f[j] -= f[j + i];

		rep(j, -i + 1, 0) 
			f[j + M] += pref * (i - abs(j));
		pref *= i;
	}

	Z res = 0;
	rep(i, M + 1, D)
		res += f[i];
	cout << res << '\n';
	return 0;
}