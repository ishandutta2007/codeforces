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

vector<int> G[100005];
int n, q;
int pa[100005];

void dfs(int v, int par)
{
	pa[v] = par;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u != par) dfs(u, v);
	}
}

double pro[100005], ss[100005], ans;

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		scanf("%lf", &pro[i]);
		pro[i] = 1.0 - pro[i];
		ans += pro[i];
	}
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		ans -= pro[u] * pro[v];
	}
	
	dfs(0, -1);
	rep(i, n) if(pa[i] != -1)
	ss[pa[i]] += pro[i];
	
	scanf("%d", &q);
	rep(i, q) {
		int v;
		double np;
		scanf("%d%lf", &v, &np);
		np = 1.0 - np;
		ss[pa[v]] -= pro[v];
		ans -= pro[v];
		ans += pro[v] * ss[v];
		if(pa[v] != -1) ans += pro[v] * pro[pa[v]];
		
		pro[v] = np;
		ss[pa[v]] += pro[v];
		ans += pro[v];
		ans -= pro[v] * ss[v];
		if(pa[v] != -1) ans -= pro[v] * pro[pa[v]];
		
		printf("%lf\n", ans);
	}
	return 0;
}