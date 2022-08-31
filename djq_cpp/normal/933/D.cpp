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
const int MOD = 1e9 + 7;
const long double EPS = 1e-16;
struct ModuloM{
	LL dat;
	ModuloM(LL f = 0LL)
	{
		dat = f % MOD;
	}
	ModuloM operator+(const ModuloM& oth) const
	{
		return ModuloM((dat + oth.dat) % MOD);
	}
	ModuloM operator-(const ModuloM& oth) const
	{
		return ModuloM((dat - oth.dat + MOD) % MOD);
	}
	ModuloM operator*(const ModuloM& oth) const
	{
		return ModuloM((dat * oth.dat) % MOD);
	}
	ModuloM power(int T) const
	{
		ModuloM ans = 1LL, cc = dat;
		while(T) {
			if(T & 1) ans = ans * cc;
			cc = cc * cc;
			T >>= 1;
		}
		return ans;
	}
	ModuloM operator /(const ModuloM& oth) const
	{
		return operator*(oth.power(MOD - 2));
	}
};

ModuloM T0(ModuloM a, ModuloM m)
{
	return (ModuloM(2) * m * m * m + ModuloM(6) * m * m + ModuloM(4) * m
			+ (ModuloM(6) * m + ModuloM(8)) * a * a
			- (ModuloM(6) * m + ModuloM(12)) * a * a * a * a
			+ ModuloM(4) * a * a * a * a * a * a);
}

ModuloM T2(ModuloM a, ModuloM m)
{
	return (ModuloM(6) * m + ModuloM(8) - (ModuloM(12) * m + ModuloM(24)) * a * a
			+ ModuloM(12) * a * a * a * a);
}
ModuloM T4(ModuloM a, ModuloM m)
{
	return ModuloM(0) - ModuloM(6) * m - ModuloM(12) + ModuloM(12) * a * a;
}
ModuloM T6(ModuloM a, ModuloM m)
{
	return ModuloM(4);
}
ModuloM solve(const vector<ModuloM>& poly, ModuloM x)
{
	ModuloM ans, cx(1);
	rep(k, poly.size()) {
		ans = ans + cx * poly[k];
		cx = cx * x;
	}
	return ans;
}
ModuloM P0(ModuloM lim)
{
	return lim;
}
ModuloM P2(ModuloM lim)
{
	return lim * (lim + ModuloM(1)) * (lim + lim + ModuloM(1)) * ModuloM(166666668);
}
ModuloM P4(ModuloM lim)
{
	vector<ModuloM> cc;
	cc.push_back(-1);
	cc.push_back(1);
	cc.push_back(9);
	cc.push_back(6);
	return solve(cc, lim) * lim * (lim + ModuloM(1)) * ModuloM(233333335);
}
ModuloM P6(ModuloM lim)
{
	vector<ModuloM> cc;
	cc.push_back(1);
	cc.push_back(-1);
	cc.push_back(-6);
	cc.push_back(6);
	cc.push_back(15);
	cc.push_back(6);
	return solve(cc, lim) * lim * (lim + ModuloM(1)) * ModuloM(23809524);
}
int main()
{
	/*
	ans = 1/12 * 
	(sigma(cnt[i]) * (2 * n * n * n + 6 * n * n + 4 * n)
	+ sigma(i * cnt[i]) * (6 * n + 8)
	- sigma(i * i * cnt[i]) * (6 * n + 12)
	+ sigma(i * i * i * cnt[i]) * 4);
	
	that is,
	ans = 1/12 *
	sigma((2 * n * n * n + 6 * n * n + 4 * n)
	+ (a * a + b * b) * (6 * n + 8)
	- (a * a + b * b) ^ 2 * (6 * n + 12)
	+ (a * a + b * b) ^ 3) * 4 for all valid pairs (a, b) such that a * a + b * b <= n)
	
	or,
	ans = 1/12 *
	sigma((2 * n^3 + 6 * n^2 + 4 * n)
	+ (a^2 + b^2) * (6 * n + 8)
	- (a^4 + 2 * a^2 * b^2 + b^4) * (6 * n + 12)
	+ (a^6 + 3 * a^4 * b^2 + 3 * a^2 * b^4 + b^6) * 4 for all valid pairs (a, b))
	
	which means,
	ans = 1/12 *
	sigma(1 <= a <= sqrt(m), (sigma(1 <= b <= sqrt(m - a^2), 1) * (2 * m^3 + 6 * m^2 + 4 * m + a^2 * (6 * m + 8) - (6 * m + 12) * a^4 + 4 * a^6)
							+sigma(1 <= b <= sqrt(m - a^2), b^2) * (6 * m + 8 - (12 * m + 24) * a^2 + 12 * a^4)
							+sigma(1 <= b <= sqrt(m - a^2), b^4) * (- 6 * m - 12 + 12 * a^2)
							+sigma(1 <= b <= sqrt(m - a^2), b^6) * 4) * 4
							+(b == 0) ... * 2)
	*/ 
	LL m;
	ModuloM ans;
	cin >> m;
	for(int a = 0; LL(a) * a <= m; a ++) {
		int mb = sqrt(m - (long double)(a) * a + EPS) + EPS;
		ModuloM cur = P0(mb) * T0(a, m) + P2(mb) * T2(a, m) + P4(mb) * T4(a, m) + P6(mb) * T6(a, m);
		cur = cur * ModuloM(2);
		cur = cur + T0(a, m);
		if(a) cur = cur * ModuloM(2);
		ans = ans + cur;
	}
	cout << (ans * ModuloM(83333334)).dat << '\n';
	return 0;
}