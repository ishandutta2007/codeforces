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

int n, a[500005];
int dat[1048576];

int gcd(int u, int v)
{
	return v == 0 ? u : gcd(v, u % v);
}

void build_t()
{
	rep(i, n) dat[i + 524288] = a[i];
	for(int i = 524287; i >= 0; i --) dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);
}

void modify_t(int id, int v, int cv = 1, int cl = 0, int cr = 524287)
{
	if(cl == cr) {
		dat[cv] = v;
		return;
	}
	int mid = (cl + cr) >> 1;
	if(id <= mid) modify_t(id, v, cv << 1, cl, mid);
	else modify_t(id, v, cv << 1 | 1, mid + 1, cr);
	dat[cv] = gcd(dat[cv << 1], dat[cv << 1 | 1]);
}

bool query_t(int l, int r, int x, bool& fd, int cv = 1, int cl = 0, int cr = 524287)
{
	if(dat[cv] % x == 0) return true;
	else if(l == cl && r == cr && fd) return false;
	else if(cl == cr) {
		fd = true;
		return true;
	}
	int mid = (cl + cr) >> 1;
	if(r <= mid) return query_t(l, r, x, fd, cv << 1, cl, mid);
	if(l > mid) return query_t(l, r, x, fd, cv << 1 | 1, mid + 1, cr);
	bool ret = query_t(l, mid, x, fd, cv << 1, cl, mid);
	ret &= query_t(mid + 1, r, x, fd, cv << 1 | 1, mid + 1, cr);
	return ret;
}

bool query_t(int l, int r, int x)
{
	bool fd = false;
	return query_t(l, r, x, fd);
}

int main()
{
	int q, l, r, x;
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	build_t();
	scanf("%d", &q);
	rep(i, q) {
		scanf("%d", &l);
		if(l == 1) {
			scanf("%d%d%d", &l, &r, &x);
			printf(query_t(l - 1, r - 1, x) ? "YES\n" : "NO\n");
		} else {
			scanf("%d%d", &l, &x);
			modify_t(l - 1, x);
		}
	}
	return 0;
}