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

PII a[4], b[4];
int fil[205][205];

int main()
{
	rep(i, 4) {
		scanf("%d%d", &a[i].first, &a[i].second);
		a[i].first += 100;
		a[i].second += 100;
	}
	rep(i, 4) {
		scanf("%d%d", &b[i].first, &b[i].second);
		b[i].first += 100;
		b[i].second += 100;
	}
	sort(a, a + 4);
	for(int i = a[0].first; i <= a[3].first; i ++) for(int j = a[0].second; j <= a[3].second; j ++)
	fil[i][j] ++;
	sort(b, b + 4);
	int w = 0;
	for(int i = b[0].first; i <= b[3].first; i ++) {
		for(int j = b[0].second - w; j <= b[0].second + w; j ++)
		fil[i][j] ++;
		if(i < b[1].first) w ++;
		else w --;
	}
	for(int i = 0; i <= 200; i ++) for(int j = 0; j <= 200; j ++)
	if(fil[i][j] == 2) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}