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
int gmem[1000005];
vector<int> S[10];
int f(int x)
{
	int ans = 1;
	while(x) {
		if(x % 10 != 0) ans *= x % 10;
		x /= 10;
	}
	return ans;
}
int g(int x)
{
	if(gmem[x] != -1) return gmem[x];
	return gmem[x] = (x < 10 ? x : g(f(x)));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(gmem, -1, sizeof(gmem));
	rep1(i, 1000000) S[g(i)].push_back(i);
	int q, l, r, k;
	cin >> q;
	rep(i, q) {
		cin >> l >> r >> k;
		cout << upper_bound(S[k].begin(), S[k].end(), r) - lower_bound(S[k].begin(), S[k].end(), l) << '\n';
	}
	return 0;
}