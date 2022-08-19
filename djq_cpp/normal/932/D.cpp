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
int pre[400005][20], jump[400005][20];
LL mw[400005][20], sw[400005][20];
void getpre(int cx, int arr[][20])
{
	rep1(i, 19) arr[cx][i] = arr[arr[cx][i - 1]][i - 1];
}
int findpx(int x, LL val)
{
	for(int i = 19; i >= 0; i --)
	if(mw[x][i] < val) x = pre[x][i];
	if(sw[x][0] < val) x = pre[x][0];
	return x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = 1, q, ans = 0;
	cin >> q;
	while(q --) {
		int tp, x;
		LL val;
		cin >> tp >> x >> val;
		x ^= ans;
		val ^= ans;
		if(tp == 1) {
			n ++;
			mw[n][0] = sw[n][0] = val;
			pre[n][0] = x;
			getpre(n, pre);
			rep1(i, 19) mw[n][i] = max(mw[n][i - 1], mw[pre[n][i - 1]][i - 1]);
			jump[n][0] = findpx(x, val);
			getpre(n, jump);
			rep1(i, 19) sw[n][i] = sw[n][i - 1] + sw[jump[n][i - 1]][i - 1];
		} else {
			ans = 0;
			if(sw[x][0] <= val) {
				for(int i = 19; i >= 0; i --)
				if(sw[x][i] <= val && jump[x][i] != 0) {
					val -= sw[x][i];
					ans += (1 << i);
					x = jump[x][i];
				}
				if(sw[x][0] <= val) ans++;
			}
			cout << ans << '\n';
		}
	}
	cout << flush;
	return 0;
}