/*
Author: Dynamic JQ

Problem: Codeforces 956D - 

Time & Date(start):

Verdict:

Tags: Lines & Inverses
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
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;
const long double EPS = 1e-9;

struct BIT
{
	int n, dat[100005];
	void modify(int x, int v)
	{
		while(x <= n) {
			dat[x] += v;
			x += x & -x;
		}
	}
	int query(int x)
	{
		int ans = 0;
		while(x > 0) {
			ans += dat[x];
			x -= x & -x;
		}
		return ans;
	}
}arr;

pair<long double, int> d1[100005], d2[100005];
int to[100005], ord[100005];

int main()
{
	int n, w;
	LL ans = 0;
	scanf("%d%d", &n, &w);
	rep(i, n) {
		int x, v;
		scanf("%d%d", &x, &v);
		d1[i] = MP((v - w - EPS) / (long double)(x), i);
		d2[i] = MP((v + w + EPS) / (long double)(x), i);
	}
	sort(d1, d1 + n);
	sort(d2, d2 + n);
	rep(i, n) to[d1[i].second] = i + 1;
	rep(i, n) ord[i] = to[d2[i].second];
	arr.n = n;
	rep(i, n) {
		ans += i - arr.query(ord[i]);
		arr.modify(ord[i], 1);
	}
	printf("%I64d\n", ans);
	return 0;
}