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

struct bitre
{
	vector<int> dat;
	void setsz(int n)
	{
		dat.resize(n + 1);
	}
	void add(int x)
	{
		x ++;
		while(x < dat.size()) {
			dat[x] ++;
			x += x & (-x);
		}
	}
	int query(int x)
	{
		x ++;
		int ret = 0;
		while(x > 0) {
			ret += dat[x];
			x -= x & (-x);
		}
		return ret;
	}
};

int n, K, x[100005], r[100005], q[100005];
int rq[100005];
vector<int> hv[100005];
bitre tre[100005];

PII tmp[100005];

int query_c(int id, int l, int r)
{
	l = lower_bound(hv[id].begin(), hv[id].end(), l) - hv[id].begin();
	r = upper_bound(hv[id].begin(), hv[id].end(), r) - hv[id].begin() - 1;
	return tre[id].query(r) - tre[id].query(l - 1);
}

int main()
{
	scanf("%d%d", &n, &K);
	rep(i, n) scanf("%d%d%d", &x[i], &r[i], &q[i]);
	
	rep(i, n) rq[i] = q[i];
	sort(rq, rq + n);
	int cnt = unique(rq, rq + n) - rq;
	
	rep(i, n) {
		q[i] = lower_bound(rq, rq + cnt, q[i]) - rq;
		hv[q[i]].push_back(x[i]);
	}
	rep(i, cnt) {
		sort(hv[i].begin(), hv[i].end());
		tre[i].setsz(hv[i].size());
	}
	
	rep(i, n) tmp[i] = MP(r[i], i);
	sort(tmp, tmp + n);
	
	LL ans = 0;
	for(int i = n - 1; i >= 0; i --) {
		int cur = tmp[i].second, cr = tmp[i].first;
		for(int k = q[cur]; k >= 0 && rq[q[cur]] - rq[k] <= K; k --)
		ans += query_c(k, x[cur] - cr, x[cur] + cr);
		for(int k = q[cur] + 1; k < cnt && rq[k] - rq[q[cur]] <= K; k ++)
		ans += query_c(k, x[cur] - cr, x[cur] + cr);
		tre[q[cur]].add(lower_bound(hv[q[cur]].begin(), hv[q[cur]].end(), x[cur]) - hv[q[cur]].begin());
	}
	printf("%I64d\n", ans);
	return 0;
}