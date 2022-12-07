#include<bits/stdc++.h>

using namespace std;

typedef complex<double> base;
void fft(vector<base>& a, bool inv)
{
	int n = a.size(), j = 0;
	vector<base> roots(n / 2);
	for (int i = 1; i < n; i++) {
		int  bit = (n >> 1);
		while (j >= bit) {
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for (int i = 0; i < n / 2; i++) {
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	for (int i = 2; i <= n; i <<= 1) {
		int step = n / i;
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < i / 2; k++) {
				base u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
		}
	}
	if (inv) for (int i = 0; i < n; i++) a[i] /= n;
}

vector<long long> multiply(vector<long long>& v, vector<long long>& w, long long MOD)
{
	int n = 2; while (n < v.size() + w.size()) n <<= 1;
	vector<base> v1(n), v2(n), r1(n), r2(n);
	for (int i = 0; i < v.size(); i++) v1[i] = base(v[i] >> 15, v[i] & 32767);
	for (int i = 0; i < w.size(); i++) v2[i] = base(w[i] >> 15, w[i] & 32767);
	fft(v1, 0); fft(v2, 0);
	for (int i = 0; i < n; i++) {
		int j = (i ? (n - i) : i);
		base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
		base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
		base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
		base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
		r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
		r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
	}
	fft(r1, 1); fft(r2, 1);
	vector<long long> ret(n);
	for (int i = 0; i < n; i++) {
		long long av = (long long)round(r1[i].real());
		long long bv = (long long)round(r1[i].imag())+ (long long)round(r2[i].real());
		long long cv = (long long)round(r2[i].imag());
		av %= MOD; bv %= MOD; cv %= MOD;
		ret[i] = (av << 30) + (bv << 15) + cv;
		ret[i] %= MOD;
		ret[i] += MOD;
		ret[i] %= MOD;
	}
	return ret;
}

const int MOD = 1e9 + 7;
vector<int> P[200001];
int SS[200002], PS[200002];

int mul(int a, int b) { return 1LL * a * b % MOD; }

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M, K, S = 0, ans = 0;
	vector<long long> A, B;
	cin >> N >> M >> K; A.resize(K); B.resize(K);
	if (K == 1) {
		cout << (mul(mul(N, M), mul(N, M)) - mul(N, M) + 1 + MOD ) % MOD << '\n';
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		cin >> PS[i];
		SS[i] = PS[i] % K;
		PS[i] += PS[i - 1];
		PS[i] %= K;
		A[PS[i]]++;
		P[PS[i]].push_back(i);
	}
	for (int i = N - 1; i >= 0; i--) {
		SS[i] += SS[i + 1];
		SS[i] %= K;
	}
	for (int i = 0; i < M - 1; i++) {
		B[S]++;
		S += SS[0];
		S %= K;
	}
	A = multiply(A, B, MOD);
	for (int i = K; i < A.size(); i++) {
		A[i - K] += A[i];
		if (A[i - K] >= MOD) A[i - K] -= MOD;
	}
	if ((S + SS[0]) % K == 0) ans = MOD - M + 1;
	for (int i = 1; i <= N; i++) {
		int v = (2 * K - SS[i] - S) % K;
		ans = (ans + 1LL * M * A[(K - SS[i]) % K]) % MOD;
		ans = (ans + 1LL * M * (lower_bound(P[v].begin(), P[v].end(), i - 1) - P[v].begin())) % MOD;
		ans = (ans + 1LL * M * (P[PS[i - 1]].end() - lower_bound(P[PS[i - 1]].begin(), P[PS[i - 1]].end(), i))) % MOD;
	}
	cout << ans << '\n';
	return 0;
}

/*
5 4 5
1 2 3 4 5
1 24 0 2
2 24 0 1
3 12 0 0
4 24 1 0
5 24 0 1
110*/