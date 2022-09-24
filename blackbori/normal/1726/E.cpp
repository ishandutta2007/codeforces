#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;
const ll M = 300000;

void test(int n) {
	int i, a = 0, b =0 ;
	vector<int> A(n), B(n);
	iota(A.begin(), A.end(), 0);
	do {
		for (i = 0; i < n; i++) {
			B[A[i]] = i;
		}
		for (i = 0; i < n; i++) {
			if (abs(A[i] - B[i]) > 1) break;
		}
		if (i == n) {
			ll f = 0;
			for (i = 0; i < n; i++) {
				ll j, l = 0;
				for (j = i, l = 1; A[j] != i; j = A[j]) l++;
				cout << l << " ";
				if (l == 4) f = 1;
			}
			cout << "\n";
			a++;
			if (f) b++;
		}
	} while (next_permutation(A.begin(), A.end()));
	cout << a << " " << b << "\n";
}

vector<ll> D(M + 2), E(M + 2), A(M + 2);
ll F[M + 2], IF[M + 2], P[M + 2];

ll pow(ll x, ll y) {
	ll z = 1;
	for (; y; y >>= 1) {
		if (y & 1) z = z * x % mod;
		x = x * x % mod;
	}
	return z;
}

ll inv(ll x) { return pow(x, mod - 2); }

void fft(vector<ll> &V, bool f) {
	ll i, j, l, k = V.size(), w, x, y;

	for (i = 1, j = 0; i < k; i++) {
		for (l = k >> 1; j >= l; l >>= 1) j -= l;
		j += l; if(i < j) swap(V[i], V[j]);
	}

	for (i = 1; i < k; i <<= 1) {
		x = (mod - 1) / i >> 1;
		w = pow(3ll, f ? mod - 1 - x : x);
		for (j = 0; j < k; j += i << 1) {
			auto u = V.begin() + j, v = u + i;
			for (l = i, x = 1; l--; u++, v++) {
				y = *v * x; *v = (*u - y) % mod;
				*u = (*u + y) % mod; x = x * w % mod;
				if (*v < 0) *v += mod;
			}
		}
	}

	if (f) {
		x = pow(k, mod - 2);
		for (i = 0; i < k; i++) {
			V[i] = V[i] * x % mod;
		}
	}
}

vector<ll> mul(vector<ll> &X, vector<ll> &Y) {
	vector<ll> P = X, Q = Y;
	ll i, k, s = X.size() + Y.size() - 1;
	for (k = 1; k < s; k <<= 1);
	P.resize(k); Q.resize(k);
	fft(P, 0); fft(Q, 0);
	for (i = 0; i < k; i ++) {
		P[i] = P[i] * Q[i] % mod;
	}
	fft(P, 1); P.resize(s);
	return P;
}

ll choose(ll n, ll k) {
	return F[n] * IF[n - k] % mod * IF[k] % mod;
}

void tc() {
	ll n, i, j, a;
	cin >> n;
	for (i = 0, a = 0; i * 4 <= n; i++) {
		// cout << choose(i + j, i) << " " << D[j] << " " << P[i] << endl;
		a = (a + choose(n - i - i, i + i) * D[n - i * 4] % mod * P[i]) % mod;
	}
	cout << a << "\n";
	// test(n);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll i;

	for (i = F[0] = P[0] = 1; i <= M; i++) {
		F[i] = F[i - 1] * i % mod;
		P[i] = P[i - 1] * (i + i - 1) * 2 % mod;
	}
	IF[M] = inv(F[M]);
	for (i = M; i >= 1; i--) {
		IF[i - 1] = IF[i] * i % mod;
	}
	
	D[0] = D[1] = 1;
	for (i = 2; i <= M; i++) {
		D[i] = (D[i - 1] + D[i - 2] * (i - 1)) % mod;
	}
	E[0] = 1;
	for (i = 4; i <= M; i += 4) {
		E[i] = E[i - 4] * 2 % mod;
	}
	A[0] = 1;
	for (i = 5; i <= M; i++) {
		A[i] = A[i - 5] * 2 % mod;
	}
//	D = mul(D, E); D.resize(M + 2);
//	D = mul(D, A); D.resize(M + 2);


	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}