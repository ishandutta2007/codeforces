/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int M = (1 << 19);

template<typename fpt>
struct fft_wrap {
	using cpx_t = complex<fpt>;
	const fpt two_pi = 4 * acosl(0);

	vector<cpx_t> roots; //stores the N-th roots of unity.
	int N;

	fft_wrap(int N) : roots(N), N(N)
	{
		for (int i = 0; i < N; ++i) {
			roots[i] = EXP(two_pi * i / fpt(N));
		}
	}

	cpx_t EXP(fpt theta)
	{
		return {cos(theta), sin(theta)};
	}

	void fft(cpx_t *in, cpx_t *out, int size, int dir)
	{
		bit_reverse(in, out, size);

		for (int s = 0; (1 << s) < size; ++s) {
			int s_ = s + 1;
			for (int k = 0; k < size; k += (1 << s_)) {
				for (int j = 0; j < (1 << s); ++j) {
					int id = (N + dir * (N >> s_) * j) & (N - 1);
					cpx_t w = roots[id];
					cpx_t t = w * out[k + j + (1 << s)];
					cpx_t u = out[k + j];
					out[k + j] = u + t;
					out[k + j + (1 << s)] = u - t;
				}
			}
		}
	}

	void bit_reverse(cpx_t *in, cpx_t *out, int size)
	{
		for (int i = 0; i < size; ++i) {
			int rev = 0, i_copy = i;
			for (int j = 0; (1 << j) < size; ++j) {
				rev = (rev << 1) + (i_copy & 1);
				i_copy >>= 1;
			}
			out[rev] = in[i];
		}
	}
};

typedef complex<long double> cpx_t;
fft_wrap<long double> fft_wrapper(M);

ll ctr[M];
vector<cpx_t> f(M), g(M), h(M), F(M), G(M), H(M);

int main() {
	fast_cin();
	int n, x;
	cin >> n >> x;
	int cur = 0;
	ctr[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		cur += (a < x);
		++ctr[cur];
	}
	for (int i = 0; i <= n; ++i) {
		f[i] = ctr[i];
		g[i] = ctr[n - i];
	}
	for (int i = n + 1; i < M; ++i) {
		f[i] = g[i] = 0;
	}
	fft_wrapper.fft(&f[0], &F[0], M, 1);
	fft_wrapper.fft(&g[0], &G[0], M, 1);
	for (int i = 0; i < M; ++i) {
		H[i] = F[i] * G[i];
	}
	fft_wrapper.fft(&H[0], &h[0], M, -1);
	for (int i = 0; i < M; ++i) {
		h[i] /= M;
	}
	ll ans_0 = 0;
	for (int i = 0; i <= n; ++i) {
		ans_0 += (ctr[i] * (ctr[i] - 1)) / 2;
	}
	cout << ans_0 << ' ';
	for (int i = 1; i <= n; ++i) {
		cout << ll(round(h[n - i].real())) << ' ';
	}
}