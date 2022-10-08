#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

typedef complex<double> base;
#include <complex>
namespace FFT {
	// blog.myungwoo.kr/54
	
	typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

	const double C_PI = acos(-1);

	void fft(vector <base> &a, bool invert) {
		int n = sz(a);
		for (int i = 0, j = 0; i<n; ++i) {
			if (i>j) swap(a[i], a[j]);
			for (int k = n >> 1; (j ^= k)<k; k >>= 1);
		}
		for (int len = 2; len <= n; len <<= 1) {
			double ang = 2 * C_PI / len*(invert ? -1 : 1);
			base wlen(cos(ang), sin(ang));
			for (int i = 0; i<n; i += len) {
				base w(1);
				for (int j = 0; j<len / 2; j++) {
					//if ((j & 511) == 511)w = base(cos(ang * j), sin(ang * j));	//     . cos, sin     
					base u = a[i + j], v = a[i + j + len / 2] * w;
					a[i + j] = u + v;
					a[i + j + len / 2] = u - v;
					w *= wlen;
				}
			}
		}
		if (invert) {
			for (int i = 0; i<n; i++) a[i] /= n;
		}
	}

	void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res, const ll MOD) {
		vector <base> fa(all(a)), fb(all(b));
		int n = 1;
		while (n < max(sz(a), sz(b))) n <<= 1; n <<= 1;
		fa.resize(n); fb.resize(n);
		fft(fa, false); fft(fb, false);
		for (int i = 0; i<n; i++) fa[i] *= fb[i];
		fft(fa, true);
		res.resize(n);
		for (int i = 0; i<n; i++) res[i] = ((int)(fa[i].real() + (fa[i].real()>0 ? 0.5 : -0.5)));
	}
}

char in1[200000];
char in2[200000];

int r[200000][6];
int root(int x, int y) {
	return (y == r[x][y]) ? y : (r[x][y] = root(x, r[x][y]));
}

vector <base> vch1[6];
vector <base> vch2[6];
int main() {
	scanf("%s %s", in1, in2);

	int N = strlen(in1), M = strlen(in2), i, j, k;
	for (i = 0; i <= N - M; i++) for (j = 0; j < 6; j++) r[i][j] = j;

	for (i = 0; i < 6; i++) {
		vector <int> Vu;
		Vu.resize(262144);
		for (j = 0; j < 262144; j++) Vu[j] = 0;
		for (j = 0; j < N; j++) if (in1[j] == 'a' + i) Vu[j] = 1;
		vector <base> vch(all(Vu));
		FFT::fft(vch, false);
		vch1[i] = vch;
	}
	for (i = 0; i < 6; i++) {
		vector <int> Vu;
		Vu.resize(262144);
		for (j = 0; j < 262144; j++) Vu[j] = 0;
		for (j = 0; j < M; j++) if (in2[j] == 'a' + i) Vu[M-1-j] = 1;
		vector <base> vch(all(Vu));
		FFT::fft(vch, false);
		vch2[i] = vch;
	}
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			vector <base> vch;
			vch.resize(262144);
			for (int k = 0; k < 262144; k++) vch[k] = vch1[i][k] * vch2[j][k];
			FFT::fft(vch, true);

			for (int k = 0; k <= N - M; k++) {
				int t = ((int)(vch[k+M-1].real() + (vch[k+M-1].real() > 0 ? 0.5 : -0.5)));
				if (t == 0) continue;
				r[k][root(k, i)] = root(k, j);
			}
		}
	}

	for (i = 0; i <= N-M; i++) {
		int ans = 6;
		for (j = 0; j < 6; j++) if (r[i][j] == j) ans--;
		printf("%d ", ans);
	}
	return 0;
}