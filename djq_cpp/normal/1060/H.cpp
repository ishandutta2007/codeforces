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

int d, MOD;
int inv[5005];
void init_inv()
{
	inv[1] = 1;
	for(int i = 2; i <= 5000; i ++) inv[i] = 1LL * inv[MOD % i] * (MOD - MOD / i) % MOD;
}

int coef2(int x)
{
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i <= d; i ++) if(i != x) {
		sum1 = (sum1 + i) % MOD;
		sum2 = (sum2 + i * i) % MOD;
	}
	sum1 = (1LL * sum1 * sum1 - sum2 + MOD) % MOD * inv[2] % MOD;
	
	for(int i = 0; i <= d; i ++) if(i < x) sum1 = 1LL * sum1 * inv[x - i] % MOD;
	else if(i > x) sum1 = MOD - 1LL * sum1 * inv[i - x] % MOD;
	return sum1 % MOD;
}

int tot = 2;
void _add(int u, int v, int w)
{
	printf("+ %d %d %d\n", u, v, w);
}

int pw2[35];
void init_pw()
{
	pw2[0] = 5000;
	rep1(i, 30) {
		pw2[i] = pw2[i - 1] - 1;
		_add(pw2[i - 1], pw2[i - 1], pw2[i]);
	}
}

int cons(int c)
{
	int to = ++ tot;
	c = (c + MOD - 1) % MOD;
	for(int i = 0; c; i ++)
	if(c >> i & 1) {
		_add(to, pw2[i], to);
		c ^= 1 << i;
	}
	return to;
}

int add(int u, int v)
{
	int to = ++ tot;
	_add(u, v, to);
	return to;
}

int ttimes(int from, int t)
{
	int to = cons(0);
	for(int i = 0; t; i ++) {
		if(t >> i & 1) {
			t ^= 1 << i;
			_add(to, from, to);
		}
		_add(from, from, from);
	}
	return to;
}

int dpower(int from)
{
	int to = ++ tot;
	printf("^ %d %d\n", from, to);
	return to;
}

int tx[5005] = {1}, ty[5005] = {2}, txy[5005];

//can be optimalized but I don't want to QAQ
int main()
{
	scanf("%d%d", &d, &MOD);
	init_inv();
	
	init_pw();
	txy[0] = add(tx[0], ty[0]);
	rep1(i, d) {
		tx[i] = add(tx[i - 1], 5000);
		ty[i] = add(ty[i - 1], 5000);
		txy[i] = add(tx[i], ty[0]);
	}
	for(int i = 0; i <= d; i ++) {
		tx[i] = dpower(tx[i]);
		ty[i] = dpower(ty[i]);
		txy[i] = dpower(txy[i]);
	}
	for(int i = 0; i <= d; i ++) txy[i] = add(txy[i], ttimes(add(tx[i], ty[i]), MOD - 1));
	for(int i = 0; i <= d; i ++) txy[i] = ttimes(txy[i], coef2(i));
	int ret = cons(0);
	for(int i = 0; i <= d; i ++) _add(ret, txy[i], ret);
	ret = ttimes(ttimes(ret, inv[d]), inv[d - 1]);
	printf("f %d\n", ret);
	return 0;
}