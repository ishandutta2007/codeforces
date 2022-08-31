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

const int MAXD = 100000;
const int MAXS = 2 * MAXD + 3;
const int MAXB = 8 * MAXD + 1;
struct BIT
{
	int tree[MAXS + 5];
	inline int lowbit(int v)
	{
		return v & (-v);
	}
	BIT()
	{
		memset(tree, 0, sizeof(tree));
	}
	int query(int id)
	{
		int ans = 0;
		while(id > 0) {
			ans += tree[id];
			id -= lowbit(id);
		}
		return ans;
	}
	int query(int l, int r)
	{
		return query(r) - query(l - 1);
	}
	void modify(int id, int v)
	{
		while(id <= MAXS) {
			tree[id] += v;
			id += lowbit(id);
		}
	}
};
bool vis[MAXB][4];
int ABS(int x)
{
	return x < 0 ? -x : x;
}
PII getnxt(const set<PII>& S, int dat, int dir)
{
	if(dir == 1) {
		set<PII>::iterator it = S.lower_bound(MP(dat, INF));
		assert(it != S.end());
		return *it;
	} else if(dir == -1) {
		set<PII>::iterator it = S.lower_bound(MP(dat, -1));
		assert(it != S.begin());
		return *(--it);
	}else assert(false);
}
namespace trans
{
	map<PII, int> bar;
	set<PII> rp[MAXS + 5], cp[MAXS + 5];
	int x[MAXB + 5], y[MAXB + 5], situ[MAXB + 5];
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
	void addbar(int cx, int cy, int sit)
	{
		int cur;
		if(bar.find(MP(cx, cy)) == bar.end()) {
			cur = bar.size();
			bar.insert(MP(MP(cx, cy), cur));
			situ[cur] = sit;
			x[cur] = cx;
			y[cur] = cy;
			rp[cx].insert(MP(cy, cur));
			cp[cy].insert(MP(cx, cur));
		} else {
			cur = bar[MP(cx, cy)];
			situ[cur] |= sit;
		}
	}
	int getbar(int id, int dir)
	{
		if(dir & 1) return getnxt(rp[x[id]], y[id], dy[dir]).second;
		else return getnxt(cp[y[id]], x[id], dx[dir]).second;
	}
	int getdir(int id, int dir)
	{
		if(!(situ[id] >> dir & 1)) return dir;
		int cc = situ[id] ^ (1 << dir);
		if(cc == 1) return 2;
		if(cc == 2) return 3;
		if(cc == 4) return 0;
		if(cc == 8) return 1;
		return dir ^ 2;
	}
}
void formalise(vector<PII>& vec)
{
	for(int i = 1; i < vec.size(); i ++)
	if(vec[i - 1].second >= vec[i].first) vec[i] = MP(min(vec[i - 1].first, vec[i].first), max(vec[i - 1].second, vec[i].second));
	for(int i = vec.size() - 2; i >= 0; i --)
	if(vec[i + 1].first <= vec[i].second) vec[i] = vec[i + 1];
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
}
namespace plcnt
{
	int lb = MAXS, rb = 0;
	int ld = MAXS, rd = 0;
	int OE;
	BIT hv[2];
	vector<int> bp[MAXS + 5], ep[MAXS + 5];
	vector<PII> row[MAXS + 5], col[MAXS + 5];
	void addseg(PII p1, PII p2)
	{
		if(p1 > p2) swap(p1, p2);
		lb = min(lb, p1.first); ld = min(ld, p1.second);
		rb = max(rb, p2.first); rd = max(rd, p2.second);
		if(p1.first == p2.first) row[p1.first].push_back(MP(p1.second, p2.second));
		else {
			assert(p1.second == p2.second);
			col[p1.second].push_back(MP(p1.first, p2.first));
		}
	}
	void frmseg()
	{
		for(int i = lb; i <= rb; i ++) {
			if(row[i].empty()) continue;
			sort(row[i].begin(), row[i].end());
			formalise(row[i]);
		}
		for(int i = ld; i <= rd; i ++) {
			if(col[i].empty()) continue;
			sort(col[i].begin(), col[i].end());
			formalise(col[i]);
		}
	}
	void modify(int v, int dat)
	{
		hv[v & 1].modify((v >> 1) + 1, dat);
	}
	int query(int id, int l, int r)
	{
		if((l + id + OE) & 1) l ++;
		if((r + id + OE) & 1) r --;
		return hv[id + OE & 1].query((r >> 1) + 1) - hv[id + OE & 1].query(l >> 1);
	}
	LL getinter()
	{
		LL ans = 0LL;
		for(int i = ld; i <= rd; i ++) rep(j, col[i].size()) {
			bp[col[i][j].first].push_back(i);
			ep[col[i][j].second].push_back(i);
		}
		for(int i = lb; i <= rb; i ++) {
			rep(j, bp[i].size()) modify(bp[i][j], 1);
			ans += query(i, ld, rd);
			rep(j, row[i].size()) {
				ans += ((row[i][j].second - row[i][j].first) >> 1) + (!((row[i][j].first + i + OE) & 1) && !((row[i][j].second + i + OE) & 1));
				ans -= query(i, row[i][j].first, row[i][j].second);
			}
			rep(j, ep[i].size()) modify(ep[i][j], -1);
		}
		return ans;
	}
}
LL solve(int bx, int by, int bd)
{
	int ci = trans::bar[MP(bx, by)];
	while(!vis[ci][bd]) {
		vis[ci][bd] = true;
		int nc = trans::getbar(ci, bd);
		plcnt::addseg(MP(trans::x[ci], trans::y[ci]), MP(trans::x[nc], trans::y[nc]));
		ci = nc;
		bd = trans::getdir(nc, bd);
	}
	plcnt::frmseg();
	return plcnt::getinter();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	rep(i, t) {
		int x, y;
		cin >> x >> y;
		trans::addbar(x + y - 2, x - y + m, 4);
		trans::addbar(x + y - 1, x - y + m - 1, 8);
		trans::addbar(x + y, x - y + m, 1);
		trans::addbar(x + y - 1, x - y + m + 1, 2);
	}
	for(int i = 0; i <= m; i ++) {
		trans::addbar(i, m - i, 3);
		trans::addbar(n + i, n + m - i, 12);
	}
	for(int i = 0; i <= n; i ++) {
		trans::addbar(i, m + i, 9);
		trans::addbar(m + i, i, 6);
	}
	int x, y;
	string bs;
	cin >> x >> y >> bs;
	trans::addbar(x + y - 1, x - y + m, 0);
	plcnt::OE = !(m & 1);
	cout << solve(x + y - 1, x - y + m, bs == "NE" ? 1 : (bs == "NW" ? 0 : (bs == "SE" ? 2 : 3))) << '\n';
	return 0;
}
//1449 3728