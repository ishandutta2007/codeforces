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
const int INF = 1e9 + 7;

const int MAGIC = 450;
int a[200005];
vector<int> qy[505][505];
int ql[200005], qr[200005];
LL cnt[1000005], cur, ans[200005];

void add_ele(int v)
{
	cur += (cnt[v] * 2 + 1) * v;
	cnt[v] ++;
}

void rem_ele(int v)
{
	cnt[v] --;
	cur -= (cnt[v] * 2 + 1) * v;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, q) {
		scanf("%d%d", &ql[i], &qr[i]);
		ql[i] --;
		qr[i] --;
		qy[ql[i] / MAGIC][qr[i] / MAGIC].push_back(i);
	}
	int cl = 0, cr = -1;
	rep(i, MAGIC) rep(j, MAGIC) rep(k, qy[i][j].size())
	{
		int id = qy[i][j][k];
		while(cr < qr[id]) {
			cr ++;
			add_ele(a[cr]);
		}
		while(cl > ql[id]) {
			cl --;
			add_ele(a[cl]);
		}
		while(cr > qr[id]) {
			rem_ele(a[cr]);
			cr --;
		}
		while(cl < ql[id]) {
			rem_ele(a[cl]);
			cl ++;
		}
		ans[id] = cur;
	}
	rep(i, q) printf("%I64d\n", ans[i]);
	return 0;
}