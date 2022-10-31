#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
const int MOD = 998244353;

template <int mod>
struct mod_int {
	int x;
	inline mod_int() {}
	inline mod_int(int a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
	}
	inline mod_int(long long a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
	}
	inline mod_int& operator=(int a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
		return *this;
	}

	inline mod_int& operator=(long long a) {
		if(a < 0) a = -a;
		if(a > mod) x = a % mod;
		else x = a;
		return *this;
	}

	inline mod_int operator-(const mod_int& e) const {
		return mod_int(x - e.x);
	}

	inline mod_int& operator+=(const mod_int& e) {
		x += e.x;
		if(x >= mod)
			x -= mod;
		return *this;
	}

	inline mod_int operator+(const mod_int& e) {
		const int val = x + e.x;
		if(val >= mod) return mod_int(val-mod);
		return mod_int(val);
	}

	inline mod_int operator*(const mod_int& e) {
		return mod_int(x * (long long)e.x);
	}

	inline mod_int operator*(const int a) {
		return *this * mod_int(a);
	}
};

template <int mod>
inline mod_int<mod> operator*(int a, mod_int<mod> m) {
	return m * a;
}

template <int mod>
istream& operator>>(istream& i, mod_int<mod>& m) {
	return i >> m.x;
}

template <int mod>
ostream& operator<<(ostream& o, const mod_int<mod>& m) {
	return o << m.x;
}

typedef mod_int<MOD> mint;
///////////////////////////////////////////

const int N = 1e5+5;
const int B = 11;
int a[N];
mint p10[50];

ll f(int a, int b) {
	vector<int> A, B, C;
	while(a) {
		A.push_back(a%10);
		a /= 10;
	}
	while(b) {
		B.push_back(b%10);
		b /= 10;
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	while(A.size() || B.size()) {
		if(B.size()) {
			C.push_back(B.back());
			B.pop_back();
		}
		if(A.size()) {
			C.push_back(A.back());
			A.pop_back();
		}
	}
	ll num = 0;
	while(C.size()) {
		num *= 10;
		num += C.back();
		C.pop_back();
	}
	return num;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);

	p10[0] = 1;
	for(int i = 1; i < 50; ++i) {
		p10[i] = p10[i-1] * 10;
	}

	int n;
	cin >> n;
	vector<int> len(B);
	mint ans = 0;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		++len[to_string(a[i]).size()];
	}
	for(int i = 0; i < n; ++i) {
		for(int l = 1; l < B; ++l) {
			if(len[l] == 0) continue;
			int b = a[i], ctr = 0;
			while(b) {
				mint dig = b % 10;
				int pa, pb;
				if(ctr < l) {
					pa = 2*ctr;
					pb = pa+1;
				} else {
					pa = 2*l + (ctr-l);
					pb = pa;
				}
				ans += len[l] * p10[pa] * dig;
				ans += len[l] * p10[pb] * dig;
				b /= 10;
				++ctr;
			}
		}
	}
	cout << ans << '\n';
}