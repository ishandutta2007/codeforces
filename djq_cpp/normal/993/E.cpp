#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

namespace FFT
{
	const long double pi = atan(1.0) * 4;
	const int SZ = 19;
	typedef complex<long double> cmplx;
	bool fli;
	cmplx uniroot(int n)
	{
		cmplx ret(cos(pi * 2.0 / n), sin(pi * 2.0 / n));
		if(fli) ret = (long double)1.0 / ret;
		return ret;
	}
	void DFT(cmplx from[], cmplx to[])
	{
		int cur = 0;
		rep(i, 1 << SZ) {
			to[i] = from[cur];
			for(int j = SZ - 1; j >= 0; j --) {
				cur ^= 1 << j;
				if(cur >> j & 1) break;
			}
		}
		for(int d = 2; d <= (1 << SZ); d <<= 1) {
			cmplx rt = uniroot(d);
			for(int i = 0; i < (1 << SZ); i += d) {
				cmplx cr = 1.0;
				for(int j = i; j < i + (d >> 1); j ++) {
					cmplx fe = to[j], fo = to[j + (d >> 1)] * cr;
					to[j] = fe + fo;
					to[j + (d >> 1)] = fe - fo;
					cr = cr * rt;
				}
			}
		}
	}
	void multiply(cmplx u[], cmplx v[], cmplx res[])
	{
		fli = false;
		DFT(u, res);
		DFT(v, u);
		rep(i, 1 << SZ) v[i] = u[i] * res[i];
		fli = true;
		DFT(v, res);
		rep(i, 1 << SZ) res[i] = res[i] * ((long double)(1.0) / (1 << SZ));
	}
}

LL dat[200005];
FFT::cmplx tmp0[524288], tmp1[524288], tmp2[524288];

int main()
{
	int n, x, y, tot = 0;
	scanf("%d%d", &n, &x);
	dat[0] ++;
	rep1(i, n) {
		scanf("%d", &y);
		tot += y < x;
		dat[tot] ++;
	}
	for(int i = 0; i <= n; i ++) tmp0[i] = dat[i];
	for(int i = 0; i <= n; i ++) tmp1[i] = dat[n - i];
	FFT::multiply(tmp0, tmp1, tmp2);
	rep1(i, n) dat[i] = tmp2[i + n].real() + 0.5;
	dat[0] = LL(n + 1) * n / 2;
	rep1(i, n) dat[0] -= dat[i];
	for(int i = 0; i <= n; i ++) printf("%I64d ", dat[i]);
	return 0;
}