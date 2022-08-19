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
const int INF = 3e8;
int l[100005], e[100005];

int min_dist(int n, int p[], int l, int r)
{
	int pos = lower_bound(p, p + n, l) - p;
	if(p[pos] <= r) return 0;
	if(pos == 0) return p[pos] - r;
	return min(p[pos] - r, l - p[pos - 1]);
}

int main()
{
	int n, m, q, cl, ce, v;
	scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
	rep(i, cl) scanf("%d", &l[i]); l[cl] = INF;
	rep(i, ce) scanf("%d", &e[i]); e[ce] = INF;
	scanf("%d", &q);
	rep(i, q) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		int tl, te;
		tl = te = y2 - y1;
		if(x1 != x2) {
			tl += min_dist(cl, l, y1, y2) * 2;
			te += min_dist(ce, e, y1, y2) * 2;
		}
		tl += x2 - x1;
		te += (x2 - x1 - 1) / v + 1;
		printf("%d\n", min(tl, te));
	}
	return 0;
}