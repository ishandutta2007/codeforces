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

int get_inter(const vector<LL>& cur)
{
	printf("%d", cur.size() - 2);
	rep1(i, cur.size() - 2) printf(" %I64d", cur[i]);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

LL dp[6][10005];

int main()
{
	rep1(i, 10000) dp[0][i] = 0;
	rep1(i, 5) rep1(j, 10000) {
		if(i == 5 && j > 1) continue; 
		dp[i][j] = dp[i - 1][j];
		rep(k, j) dp[i][j] += dp[i - 1][min(j + dp[i][j] + 1, 10000LL)] + 1;
	}
	
	LL l = 1, r = 10004205361450474;
	int cr = 5;
	
	while(l <= r) {
		cr --;
		
		vector<LL> cur;
		cur.push_back(l - 1);
		while(cur.back() <= r) {
			LL ct = cur.back() + 1;
			ct += dp[cr][min(ct, 10000LL)];
			cur.push_back(ct);
		}
		
		if(cur.size() <= 2) continue;
		
		int k = get_inter(cur);
		if(k == -1) break;
		
		l = cur[k] + 1;
		r = cur[k + 1] - 1;
	}
	
	return 0;
}