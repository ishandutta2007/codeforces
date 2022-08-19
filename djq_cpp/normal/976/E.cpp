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

PII dif[200005];
bool cmp(PII x, PII y)
{
	return x.first - x.second > y.first - y.second;
}
LL prs[200005];

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	b = min(b, n);
	rep(i, n) scanf("%d%d", &dif[i].first, &dif[i].second);
	sort(dif, dif + n, cmp);
	LL sum = 0, ans = 0;
	rep(i, n) sum += dif[i].second;
	rep(i, n) prs[i] = (i == 0 ? 0 : prs[i - 1]) + max(dif[i].first - dif[i].second, 0);
	if(b == 0) {
		printf("%I64d\n", sum);
		return 0;
	}
	ans = sum + prs[b - 1];
	rep(i, n) {
		LL cur = prs[b - 1];
		if(i < b) {
			cur -= max(dif[i].first - dif[i].second, 0);
		} else cur -= max(dif[b - 1].first - dif[b - 1].second, 0);
		cur += max((LL(dif[i].first) << a) - dif[i].second, 0LL);
		ans = max(ans, sum + cur);
	}
	printf("%I64d\n", ans);
	return 0;
}