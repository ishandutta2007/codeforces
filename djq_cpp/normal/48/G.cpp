/*
Author: djq_cpp

Time & Date(start): Mar/2/2018 18:39

Problem: Codeforce 48G: Galaxy Union
*/

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

int n;
vector<PII> G[200005];

vector<PII> cyc;
vector<PII> son[200005];
int incy[200005], grp[200005], sz[200005];
LL dist[200005], otd[200005];
int pres[400005];

LL ans[200005], dep[200005];

namespace gcyc
{
	int find_cyc(int v, int par)
	{
		incy[v] = 1;
		cyc.push_back(MP(v, -1));
		rep(i, G[v].size()) {
			int u = G[v][i].first;
			if(u == par) continue;
			cyc.back().second = G[v][i].second;
			if(!incy[u]) {
				int sit = find_cyc(u, v);
				if(sit != -1) return sit;
			} else if(incy[u] == 1) return u;
		}
		incy[v] = -1;
		cyc.pop_back();
		return -1;
	}
	
	void find_cyc()
	{
		int bp = find_cyc(1, 0);
		rep(i, cyc.size()) {
			if(cyc[i].first == bp) {
				cyc.erase(cyc.begin(), cyc.begin() + i);
				break;
			}
			incy[cyc[i].first] = 0;
		}
		rep1(i, n) if(incy[i] == -1) incy[i] = 0;
	}
}
namespace gtree{
	void get_tre(int v, int gp, int d, LL& cur)
	{
		incy[v] = 1;
		grp[v] = gp;
		sz[v] = 1;
		dep[v] = d;
		rep(i, G[v].size()) {
			int u = G[v][i].first;
			if(incy[u]) continue;
			get_tre(u, gp, d + G[v][i].second, cur);
			cur += sz[u] * G[v][i].second;
			sz[v] += sz[u];
			son[v].push_back(MP(u, G[v][i].second));
		}
	}
	
	void get_dis(int v, int tot, LL cd)
	{
		dist[v] = cd;
		rep(i, son[v].size()) {
			int u = son[v][i].first;
			cd += son[v][i].second * (tot - 2 * sz[u]);
			get_dis(u, tot, cd);
			cd -= son[v][i].second * (tot - 2 * sz[u]);
		}
	}
	
	void get_info()
	{
		rep(i, cyc.size()) {
			int v = cyc[i].first;
			LL cur = 0LL;
			get_tre(v, i, 0, cur);
			get_dis(v, sz[v], cur);
		}
	}
}

namespace gcycd
{
	int rgsum(int l, int r, bool ff = true)
	{
		return ff ? pres[r] - pres[l] : pres[cyc.size()] + pres[r] - pres[l];
	}
	
	int getsz(int x)
	{
		if(x >= cyc.size()) x -= cyc.size();
		return sz[cyc[x].first];
	}
	
	void get_otd()
	{
		int pos = 0, cnt = 0;
		LL cd = 0LL;
		rep(i, cyc.size()) pres[i + 1] = pres[i] + cyc[i].second;
		rep(i, cyc.size()) pres[i + cyc.size() + 1] = pres[i + cyc.size()] + cyc[i].second;
		rep(i, cyc.size()) cd += rgsum(i, 0, false) * getsz(i);
		rep(i, cyc.size()) {
			while(rgsum(i, pos, true) < rgsum(pos, i, false)) {
				cnt += getsz(pos);
				cd += (rgsum(i, pos, true) - rgsum(pos, i, false)) * getsz(pos);
				pos ++;
			}
			otd[i] = cd;
			cd += (n - 2 * (cnt - getsz(i))) * cyc[i].second;
			cnt -= getsz(i);
		}
	}
}

void get_ans()
{
	gcyc::find_cyc();
	gtree::get_info();
	gcycd::get_otd();
	LL tot = 0LL;
	rep(i, cyc.size()) tot += dist[cyc[i].first];
	rep1(i, n) {
		int rt = cyc[grp[i]].first;
		ans[i] = dist[i] + tot - dist[rt] + otd[grp[i]] + dep[i] * (n - sz[rt]);
	}
}

int main()
{
	scanf("%d", &n);
	rep(i, n) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(MP(v, w));
		G[v].push_back(MP(u, w));
	}
	get_ans();
	rep1(i, n) printf("%I64d ", ans[i]);
	return 0;
}