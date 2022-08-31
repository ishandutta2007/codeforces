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

int n, m;
LL a[105];
LL aa, ab, af, as;

int getal(int s, int ssm, int lsm)
{
	int tot = 0;
	rep(i, n) {
		int cur = a[i] % s;
		if(cur * 2 < s) ssm = max(ssm, cur + 1);
		else {
			ssm = max(ssm, cur / 2 + 1);
			ssm = max(ssm, s - cur);
			tot ^= 1;
		}
	}
	return !tot ? max(lsm - ssm + 1, 0) : 0;
}

int getbw(int s, int ssm, int lsm)
{
	int mx0 = -1, mx1 = -1;
	int tot = 0;
	rep(i, n) {
		int cur = a[i] % s;
		if(cur * 2 < s) ssm = max(ssm, cur + 1);
		else {
			ssm = max(ssm, s - cur);
			tot ^= 1;
			
			if(cur > mx0) {
				mx1 = mx0;
				mx0 = cur;
			} else if(cur > mx1) mx1 = cur;
		}
	}
	if(mx1 != -1) ssm = max(ssm, mx1 / 2 + 1);
	
	return tot ? max(lsm - ssm + 1, 0) : 0;
}

void upd_sum(int s, int ssm, int lsm)
{
	int tot = lsm - ssm + 1;
	
	int al = getal(s, ssm, lsm), bw = getbw(s, ssm, lsm);
	af += bw;
	as += al;
	aa += tot - bw - al;
}

void upd_sum1(int x)
{
	int tot = 0;
	rep(i, n) tot ^= a[i] / x & 1;
	if(tot) af ++;
	else as ++;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%I64d", &a[i]);
	for(int i = 2; i < m * 2; i ++) upd_sum(i, max(1, i - m), (i - 1) / 2);
	aa = ab = aa + ab;
	af *= 2;
	as *= 2;
	rep1(i, m) upd_sum1(i);
	printf("%I64d %I64d %I64d %I64d\n", aa, ab, af, as);
	return 0;
}