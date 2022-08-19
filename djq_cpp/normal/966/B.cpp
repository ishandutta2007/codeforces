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
PII t[300005];
int nc1[300005], nc2[300005];
vector<int> ans1, ans2;

bool process(int n, int ter1[], int ter2[])
{
	int minr = -1;
	rep(i, n) if(ter2[i] < n) minr = i;
	rep(i, n) if(ter1[i] < minr) {
		for(int j = i; j <= ter1[i]; j ++) ans1.push_back(t[j].second);
		for(int j = minr; j <= ter2[minr]; j ++) ans2.push_back(t[j].second);
		return true;
	}
	return false;
}

int main()
{
	int n, x1, x2;
	scanf("%d%d%d", &n, &x1, &x2);
	rep(i, n) {
		scanf("%d", &t[i].first);
		t[i].second = i + 1;
	}
	sort(t, t + n);
	rep(i, n) nc1[i] = (x1 - 1) / t[i].first + i;
	rep(i, n) nc2[i] = (x2 - 1) / t[i].first + i;
	if(process(n, nc1, nc2)) {
		printf("Yes\n%d %d\n", ans1.size(), ans2.size());
		rep(i, ans1.size()) printf("%d ", ans1[i]); printf("\n");
		rep(i, ans2.size()) printf("%d ", ans2[i]); printf("\n");
	} else if(process(n, nc2, nc1)) {
		printf("Yes\n%d %d\n", ans2.size(), ans1.size());
		rep(i, ans2.size()) printf("%d ", ans2[i]); printf("\n");
		rep(i, ans1.size()) printf("%d ", ans1[i]); printf("\n");
	} else printf("No\n");
	return 0;
}