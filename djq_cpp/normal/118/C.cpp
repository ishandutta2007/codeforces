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

int n, k;
string s;
PII dats[10005];

pair<int, string> getans(char num)
{
	rep(i, n) if(num > s[i]) dats[i] = MP(num - s[i], 2 * n - i);
	else dats[i] = MP(s[i] - num, i);
	
	sort(dats, dats + n);
	
	pair<int, string> ans(0, s);
	rep(i, k) {
		ans.first += dats[i].first;
		
		int id = dats[i].second;
		ans.second[id >= n ? 2 * n - id : id] = num;
	}
	
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k >> s;
	
	pair<int, string> ans = MP(INF, "");
	for(char i = '0'; i <= '9'; i ++) ans = min(ans, getans(i));
	
	cout << ans.first << '\n' << ans.second << '\n';
	return 0;
}