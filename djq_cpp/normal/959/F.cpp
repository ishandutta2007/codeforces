//just a practice for linear basis
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

inline int lowbit(int x)
{
	return x & (-x);
}

struct basis
{
	vector<int> dat;
	basis()
	{
		dat.clear();
	}
	basis(const basis& oth)
	{
		dat = oth.dat;
	}
	int simplify(int v)
	{
		rep(i, dat.size())
		if(v & lowbit(dat[i])) v ^= dat[i];
		return v;
	}
	void insert(int v)
	{
		v = simplify(v);
		if(v != 0) dat.push_back(v);
	}
	int size()
	{
		return dat.size();
	}
};

int a[100005];
basis bas[100005];
int pw2[100005];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	pw2[0] = 1;
	rep1(i, n) pw2[i] = pw2[i - 1] * 2 % INF;
	rep1(i, n) {
		scanf("%d", &a[i]);
		bas[i] = bas[i - 1];
		bas[i].insert(a[i]);
	}
	rep1(i, q) {
		int l, x;
		scanf("%d%d", &l, &x);
		if(bas[l].simplify(x)) printf("0\n");
		else printf("%d\n", pw2[l - bas[l].size()]);
	}
	return 0;
}