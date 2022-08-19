/*
Author: Dynamic JQ

Problem:

Time & Date(start):

Verdict:
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

int a[100005], prm[100005], dep[100005];

int main()
{
	int n;
	LL ans = 0LL;
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) prm[i] = i ? max(prm[i - 1], a[i]) : a[i];
	for(int i = n - 1; i >= 0; i --) dep[i] = max(dep[i + 1] - 1, prm[i] + 1);
	rep(i, n) ans += dep[i] - a[i] - 1;
	printf("%I64d\n", ans);
	return 0;
}