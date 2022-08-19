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
const long double EPS = 1e-11;

struct poi
{
	int x, y;
	poi(int cx = 0, int cy = 0)
	{
		x = cx;
		y = cy;
	}
	poi operator-(const poi& oth) const
	{
		return poi(x - oth.x, y - oth.y);
	}
	bool operator<(const poi& oth) const
	{
		return MP(x, y) < MP(oth.x, oth.y);
	}
};

inline LL sqr_v(int x)
{
	return 1LL * x * x;
}

inline LL sqr_d(poi t)
{
	return sqr_v(t.x) + sqr_v(t.y);
}

inline LL mul(poi u, poi v)
{
	return 1LL * u.x * v.x + 1LL * u.y * v.y;
}

vector<poi> e1, e2;
vector<poi> eg1, eg2;

void hf_conv_h(const vector<poi>& pts, vector<poi>& ret, LL tt)
{
	ret.push_back(pts[0]);
	for(int i = 1; i < pts.size(); i ++) {
		while(ret.size() > 1) {
			poi cur = ret.back();
			ret.pop_back();
			if(tt * (cur.y - ret.back().y) * (pts[i].x - ret.back().x) >
			tt * (pts[i].y - ret.back().y) * (cur.x - ret.back().x)) {
				ret.push_back(cur);
				break;
			}
		}
		ret.push_back(pts[i]);
	}
}

void gen_conv_h(const vector<poi>& pts, vector<poi>& ret)
{
	if(pts.size() == 1) {
		ret = pts;
		return;
	}
	vector<poi> d;
	hf_conv_h(pts, ret, 1);
	hf_conv_h(pts, d, -1);
	for(int i = d.size() - 2; i >= 1; i --) ret.push_back(d[i]);
}

void equiv(const vector<poi>& pts, vector<pair<LL, LL> >& ret)
{
	rep(i, pts.size())
	ret.push_back(MP(sqr_d(pts[(i + 1) % pts.size()] - pts[i]), 
					mul(pts[(i + 1) % pts.size()] - pts[i], pts[(i + pts.size() - 1) % pts.size()] - pts[i])));
}

int fail[300005];
bool compar(const vector<poi>& pol1, const vector<poi>& pol2)
{
	if(pol1.size() != pol2.size()) return false;
	int n = pol1.size();
	vector<pair<LL, LL> > u, v;
	equiv(pol1, u);
	equiv(pol2, v);
	u.push_back(MP(-1, 0));
	rep(i, v.size()) u.push_back(v[i]);
	rep(i, v.size()) u.push_back(v[i]);
	fail[0] = -1;
	for(int i = 1; i < u.size(); i ++) {
		fail[i] = i - 1;
		do fail[i] = fail[fail[i]];
		while(fail[i] != -1 && u[i] != u[fail[i] + 1]);
		if(u[i] == u[fail[i] + 1]) fail[i] ++;
		if(fail[i] >= int(v.size() - 1)) return true;
	}
	return false;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		e1.push_back(poi(x, y));
	}
	rep(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		e2.push_back(poi(x, y));
	}
	sort(e1.begin(), e1.end());
	sort(e2.begin(), e2.end());
	gen_conv_h(e1, eg1);
	gen_conv_h(e2, eg2);
	printf(compar(eg1, eg2) ? "YES\n" : "NO\n");
	return 0;
}