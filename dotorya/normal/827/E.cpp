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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

#include <stdio.h>
#include <vector>
using namespace std;

#include <complex>
namespace FFT {
	// blog.myungwoo.kr/54
	typedef complex<double> base;
	typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

	const double C_PI = acos(-1);

	void fft(vector <base> &a, bool invert) {
		int n = sz(a);
		for (int i = 0, j = 0; i < n; ++i) {
			if (i > j) swap(a[i], a[j]);
			for (int k = n >> 1; (j ^= k) < k; k >>= 1);
		}
		for (int len = 2; len <= n; len <<= 1) {
			double ang = 2 * C_PI / len*(invert ? -1 : 1);
			base wlen(cos(ang), sin(ang));
			for (int i = 0; i < n; i += len) {
				base w(1);
				for (int j = 0; j < len / 2; j++) {
					if ((j & 511) == 511)w = base(cos(ang * j), sin(ang * j));	//     . cos, sin     
					base u = a[i + j], v = a[i + j + len / 2] * w;
					a[i + j] = u + v;
					a[i + j + len / 2] = u - v;
					w *= wlen;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < n; i++) a[i] /= n;
		}
	}

	void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res, const int MOD) {
		vector <base> fa(all(a)), fb(all(b));
		int n = 1;
		while (n < max(sz(a), sz(b))) n <<= 1; n <<= 1;
		fa.resize(n); fb.resize(n);
		fft(fa, false); fft(fb, false);
		for (int i = 0; i < n; i++) fa[i] *= fb[i];
		fft(fa, true);
		res.resize(n);
		for (int i = 0; i < n; i++) res[i] = ((ll)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5))) % MOD;
	}
}

char u[500050];

bool chk[500050];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		vector <int> V1;
		vector <int> V2;

		int N, i, j;
		scanf("%d", &N);
		for (i = 0; i < N; i++) V1.push_back(0);
		for (i = 0; i < N; i++) V2.push_back(0);
		
		scanf("%s", u);
		for (i = 0; u[i] != 0; i++) {
			if (u[i] == 'V') V1[i] = 1;
			if (u[i] == 'K') V2[N - 1 - i] = 1;
		}

		vector <int> Vr;
		FFT::multiply(V1, V2, Vr, MOD);

		for (i = 1; i <= N; i++) chk[i] = false;
		for (i = 0; i <= 2 * N - 2; i++) if(Vr[i]) chk[abs(i - N + 1)] = true;

		vector <int> Va;
		for (i = 1; i <= N; i++) {
			for (j = i; j <= N; j += i) if (chk[j]) break;
			if (j > N) Va.push_back(i);
		}
		printf("%d\n", (int)Va.size());
		for (auto it : Va) printf("%d ", it);
		printf("\n");
	}
	return 0;
}