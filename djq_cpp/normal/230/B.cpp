//just some practice
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
const int MAXN = 1000000;

int mp[1000005];
vector<int> pri;

void sieve()
{
	memset(mp, -1, sizeof(mp));
	pri.clear();
	for(int i = 2; i <= MAXN; i ++) {
		if(mp[i] == -1) pri.push_back(i);
		rep(j, pri.size()) {
			int cur = i * pri[j];
			if(cur > MAXN) break;
			mp[cur] = pri[j];
			//do something here
			if(i % pri[j] == 0) continue;
		}
	}
}

bool check(LL cur)
{
	int l = 0, r = pri.size();
	while(l < r) {
		int mid = (l + r) >> 1;
		if(1LL * pri[mid] * pri[mid] < cur) l = mid + 1;
		else r = mid;
	}
	return r < pri.size() && 1LL * pri[r] * pri[r] == cur;
}

int main()
{
	sieve();
	int q;
	LL x;
	scanf("%d", &q);
	rep(i, q) {
		scanf("%I64d", &x);
		printf(check(x) ? "YES\n" : "NO\n");
	}
	return 0;
}