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
int ans[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	for(int ac = 0; ac * a <= n; ac ++) {
		int bc = (n - ac * a) / b;
		if(ac * a + bc * b != n) continue;
		int cnt = 0;
		rep(i, ac) rep(j, a) {
			if(j) ans[cnt] = cnt;
			else ans[cnt] = cnt + a;
			cnt ++;
		}
		rep(i, bc) rep(j, b) {
			if(j) ans[cnt] = cnt;
			else ans[cnt] = cnt + b;
			cnt ++;
		}
		rep(i, n) cout << ans[i] << ' ';
		cout << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}