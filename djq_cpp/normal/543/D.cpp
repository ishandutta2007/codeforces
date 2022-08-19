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
const int MOD = 1e9 + 7;

vector<int> G[200005];

LL w[200005], ans[200005];

int sz[200005];
bool del[200005];

void gen_basi(int v, int par)
{
	sz[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par || del[u]) continue;
		gen_basi(u, v);
		sz[v] += sz[u];
	}
}
LL gen_info(int v, int par)
{
	LL ret = w[v];
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par || del[u]) continue;
		ret = ret * (gen_info(u, v) + 1) % MOD;
	}
	return ret;
}

int centroid(int v, int par, int tot)
{
	int mu = par, ms = tot - sz[v];
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par || del[u]) continue;
		if(sz[u] > ms) {
			ms = sz[u];
			mu = u;
		}
	}
	return ms * 2 <= tot ? v : centroid(mu, v, tot);
}

void deposit(int v)
{
	gen_basi(v, -1);
	v = centroid(v, -1, sz[v]);
	del[v] = true;
	vector<LL> ds;
	LL cur = 1LL;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(del[u]) continue;
		ds.push_back(cur);
		cur = cur * (gen_info(u, v) + 1) % MOD;
	}
	cur = w[v];
	for(int i = G[v].size() - 1; i >= 0; i --) {
		int u = G[v][i];
		if(del[u]) continue;
		LL cc = ds.back() * cur % MOD;
		ds.pop_back();
		cur = cur * (gen_info(u, v) + 1) % MOD;
		w[u] = w[u] * (cc + 1) % MOD;
	}
	ans[v] = cur;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(del[u]) continue;
		deposit(u);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++) {
		int v;
		scanf("%d", &v);
		G[i].push_back(v);
		G[v].push_back(i);
	}
	rep1(i, n) w[i] = 1;
	deposit(1);
	rep1(i, n) printf("%I64d\n", ans[i]);
	return 0;
}