/*
Author: Dynamic JQ

Problem: Codeforces 837E - Rusty String

Time & Date(start): May/19/2018 22:55

Verdict: Coding

Tags: FFT
*/
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
#define upd_modadd(u, v) u = v; if(u >= MOD) u -= MOD;
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

namespace NTT
{
	const LL MOD = 998244353;
	LL power(LL x, int t)
	{
		if(t == 0) return 1LL;
		LL cc = power(x, t >> 1);
		cc = cc * cc % MOD;
		if(t & 1) cc = cc * x % MOD;
		return cc;
	}
	const LL root = 3;
	int SZ;
	bool fli;
	LL uniroot(int n)
	{
		int t = (MOD - 1) / n;
		if(fli) t = MOD - 1 - t;
		return power(root, t);
	}
	void DFT(LL from[], LL to[])
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
			LL rt = uniroot(d);
			for(int i = 0; i < (1 << SZ); i += d) {
				LL cr = 1;
				for(int j = i; j < i + (d >> 1); j ++) {
					LL fe = to[j], fo = to[j + (d >> 1)] * cr % MOD;
					upd_modadd(to[j], fe + fo);
					upd_modadd(to[j + (d >> 1)], fe - fo + MOD);
					cr = cr * rt % MOD;
				}
			}
		}
	}
	void multiply(LL u[], LL v[], LL res[])
	{
		fli = false;
		DFT(u, res);
		DFT(v, u);
		rep(i, 1 << SZ) v[i] = u[i] * res[i] % MOD;
		fli = true;
		DFT(v, res);
		LL ct = power(1 << SZ, MOD - 2);
		rep(i, 1 << SZ) res[i] = res[i] * ct % MOD;
	}
}

char ch[500005];
LL pv[1048576], pk[1048576], pro[1048576];
bool ok[500005];

int abs_v(int x)
{
	return x < 0 ? -x : x;
}

void solve()
{
	int n, cnt = 0;
	scanf("%d%s", &n, &ch);
	NTT::SZ = n == 1 ? 1 : 33 - __builtin_clz(n - 1);
	rep(i, n) pv[i] = ch[i] == 'V';
	rep(i, n) pk[i] = ch[n - 1 - i] == 'K';
	NTT::multiply(pv, pk, pro);
	rep1(i, n) ok[i] = true;
	for(int i = 0; i <= (n - 1) * 2; i ++) {
		if(pro[i] == 0LL) continue;
		ok[abs_v(i - n + 1)] = false;
	}
	rep1(i, n) {
		for(int j = i + i; j <= n; j += i) ok[i] &= ok[j];
		if(ok[i]) cnt ++;
	}
	printf("%d\n", cnt);
	rep1(i, n) if(ok[i]) printf("%d ", i); printf("\n");
	rep(i, 1 << NTT::SZ) pv[i] = pk[i] = 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t) solve();
	return 0;
}