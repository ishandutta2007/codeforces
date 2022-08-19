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
const int MAXN = 10000;
struct persis_DSU
{
	int prev[MAXN + 5], sz[MAXN + 5], ep[MAXN + 5];
	vector<PII> do_list;
	persis_DSU(int n = MAXN)
	{
		rep1(i, n) {
			prev[i] = i;
			sz[i] = 1;
		}
		do_list.clear();
	}
	int root(int v, int& cnt)
	{
		if(prev[v] == v) return v;
		cnt ^= ep[v];
		return root(prev[v], cnt);
	}
	int unite(int u, int v)
	{
		int cu = 0, cv = 0;
		u = root(u, cu);
		v = root(v, cv);
		if(u == v) return cu ^ cv ^ 1;
		if(sz[u] < sz[v]) swap(u, v);
		prev[v] = u;
		ep[v] = cu ^ cv ^ 1;
		do_list.push_back(MP(u, v));
		sz[u] += sz[v];
		return -1;
	}
	void undo()
	{
		int u = do_list.back().first, v = do_list.back().second;
		prev[v] = v;
		do_list.pop_back();
		sz[u] -= sz[v];
	}
}dsu;
PII edge[MAXN + 5];
vector<int> ans;
void solve(int l, int r)
{
	if(l == r) {
		ans.push_back(l);
		return;
	}
	int mid = (l + r) >> 1;
	bool ok = true;
	int cnt = 0;
	for(int i = mid + 1; i <= r; i ++) {
		int sit = dsu.unite(edge[i].first, edge[i].second);
		if(sit == -1) cnt ++;
		if(sit == 1) ok = false;
	}
	if(ok) solve(l, mid);
	while(cnt --) dsu.undo();
	ok = true;
	cnt = 0;
	for(int i = l; i <= mid; i ++) {
		int sit = dsu.unite(edge[i].first, edge[i].second);
		if(sit == -1) cnt ++;
		if(sit == 1) ok = false;
	}
	if(ok) solve(mid + 1, r);
	while(cnt --) dsu.undo();
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if(m == 0) {
		printf("0\n");
		return 0;
	}
	rep(i, m) scanf("%d%d", &edge[i].first, &edge[i].second);
	solve(0, m-1);
	printf("%d\n", ans.size());
	rep(i, ans.size()) printf("%d ", ans[i] + 1);
	return 0;
}