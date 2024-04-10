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

int n, m, k;
vector<int> G[200005];
int ans[200005];
int deg[200005], seq[200005];
int l[200005], r[200005];

bool topo_st()
{
	queue<int> que;
	rep1(i, n) if(deg[i] == 0) que.push(i);
	rep(i, n) {
		if(que.empty()) return false;
		seq[i] = que.front();
		que.pop();
		rep(j, G[seq[i]].size()) {
			int u = G[seq[i]][j];
			deg[u] --;
			if(deg[u] == 0) que.push(u);
		}
	}
	return true;
}

void init_rg()
{
	rep(i, n) rep(j, G[seq[i]].size())
	l[G[seq[i]][j]] = max(l[G[seq[i]][j]], l[seq[i]] + 1);
	for(int i = n - 1; i >= 0; i --) rep(j, G[seq[i]].size())
	r[seq[i]] = min(r[seq[i]], r[G[seq[i]][j]] - 1);
}

vector<int> hv[200005];
set<PII> cur;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	rep1(i, n) {
		int x;
		scanf("%d", &x);
		if(x == 0) {
			l[i] = 1;
			r[i] = k;
		} else l[i] = r[i] = x;
	}
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[v].push_back(u);
		deg[u] ++;
	}
	if(!topo_st()) {
		printf("-1\n");
		return 0;
	}
	init_rg();
	rep1(i, n) if(l[i] > r[i]) {
		printf("-1\n");
		return 0;
	}
	rep1(i, n) hv[l[i]].push_back(i);
	rep1(i, k) {
		rep(j, hv[i].size()) cur.insert(MP(r[hv[i][j]], hv[i][j]));
		if(cur.empty()) {
			printf("-1\n");
			return 0;
		}
		do {
			ans[cur.begin()->second] = i;
			cur.erase(cur.begin());
		} while(!cur.empty() && cur.begin()->first == i);
	}
	rep1(i, n) printf("%d ", ans[i]);
	return 0;
}