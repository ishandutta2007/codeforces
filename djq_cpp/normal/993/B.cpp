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

int Gn[15], Gm[15];
PII a[15], b[15];

int shared1(PII x, PII y)
{
	if(x.first > x.second) swap(x.first, x.second);
	if(y.first > y.second) swap(y.first, y.second);
	if(x == y) return -1;
	if(x.first == y.first || x.first == y.second) return x.first;
	if(x.second == y.first || x.second == y.second) return x.second;
	return -1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d%d", &a[i].first, &a[i].second);
	rep(i, m) scanf("%d%d", &b[i].first, &b[i].second);
	int tot = 0;
	rep(i, n) rep(j, m) {
		int cur = shared1(a[i], b[j]);
		if(cur == -1) continue;
		Gn[i] |= 1 << cur;
		Gm[j] |= 1 << cur;
		tot |= 1 << cur;
	}
	if(__builtin_popcount(tot) == 1) printf("%d\n", __builtin_ctz(tot));
	else {
		bool ok = true;
		rep(i, n) if(__builtin_popcount(Gn[i]) > 1) ok = false;
		rep(i, m) if(__builtin_popcount(Gm[i]) > 1) ok = false;
		if(ok) printf("0\n");
		else printf("-1\n");
	}
	return 0;
}