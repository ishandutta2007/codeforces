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
const LL HRADIX = 3, HINVR = 334845270, HMOD = 1004535809;

int n, q;
char ch[200005];
LL pres[26][200005];
LL hb[200005], ihb[200005];

int query(int tp, int l, int r)
{
	return (pres[tp][r] - pres[tp][l - 1] + HMOD) * ihb[l - 1] % HMOD;
}

void h_init()
{
	hb[0] = ihb[0] = 1LL;
	rep1(i, n) {
		hb[i] = hb[i - 1] * HRADIX % HMOD;
		ihb[i] = ihb[i - 1] * HINVR % HMOD;
	}
}

int main()
{
	scanf("%d%d%s", &n, &q, &ch);
	h_init();
	rep(i, n) {
		rep(j, 26) pres[j][i + 1] = pres[j][i];
		pres[ch[i] - 'a'][i + 1] = (pres[ch[i] - 'a'][i + 1] + hb[i]) % HMOD;
	}
	int tmpx[26], tmpy[26];
	rep(i, q) {
		int x, y, l;
		scanf("%d%d%d", &x, &y, &l);
		rep(j, 26) tmpx[j] = query(j, x, x + l - 1);
		rep(j, 26) tmpy[j] = query(j, y, y + l - 1);
		sort(tmpx, tmpx + 26);
		sort(tmpy, tmpy + 26);
		bool ret = true;
		rep(j, 26) if(tmpx[j] != tmpy[j]) ret = false;
		printf(ret ? "YES\n" : "NO\n");
	}
	return 0;
}