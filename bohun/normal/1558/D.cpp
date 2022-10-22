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

template<class T, int N>
struct Newton {
	T fac[N], rev[N];
	Newton() {
		fac[0] = 1;
		for (int i = 1; i < N; i++)
			fac[i] = fac[i - 1] * T(i);
		rev[N - 1] = fac[N - 1].inv();
		for (int i = N - 1; 0 < i; i--)
			rev[i - 1] = rev[i] * T(i);
	}
	T get(int n, int k) {
		if (n < 0 || k < 0 || n - k < 0)
			return 0;
		return fac[n] * rev[n - k] * rev[k];
	}
	T bars(int n, int s) {
		return get(s + n - 1, s);
	}
};

template<typename T, int N>
struct fenwick {
	T f[N + 1];
	void add(int x, T y) {
		for (x++; x <= N; x += x & -x)
			f[x] += y;
	}
	T query(int x) {
		assert(x < N);
		T res = 0;
		for (x++; 0 < x; x -= x & -x)
			res += f[x];
		return res;
	}
	T range(int l, int r) {
		return query(r) - query(l - 1);
	};
	int kth(T s) {
		if (query(N - 1) < s) return N;
		int x = 0;
		int MST = __lg(N);
		per(b, 0, MST + 1)
			if (x + (1 << b) < N && f[x + (1 << b)] < s) {
				s -= f[x + (1 << b)];
				x += 1 << b;
			}
		return x;
	}
};

const int N = 1 << 20;
Newton<Z, N> C;
fenwick<int, N> F;
int n, m, x[N], y[N], z[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	FOR(i, N)
		F.add(i, 1);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		FOR(i, m)
			cin >> x[i] >> y[i];

		set<int> s;
		per(i, 0, m) {
			z[i] = F.kth(y[i]);
			F.add(z[i], -1);
			s.insert(F.kth(y[i]));
		}

		FOR(i, m)
			F.add(z[i], 1);

		cout << C.bars(n + 1, n - 1 - s.size()) << '\n';
	}

	return 0;
}