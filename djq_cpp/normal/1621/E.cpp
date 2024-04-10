#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, a[100005];
vector<int> hv[100005];

LL sum[100005];
int ps[200005], ts[200005], qs[200005];
PII ce[200005];
void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, m) {
		int s; scanf("%d", &s);
		hv[i].resize(s);
		rep(j, s) scanf("%d", &hv[i][j]);
		
		sum[i] = 0;
		rep(j, s) sum[i] += hv[i][j];
		ce[i] = MP((sum[i] + s - 1) / s, i);
	}
	rep(i, n) ce[i + m] = MP(a[i], i + m);
	sort(ce, ce + n + m);
	
	ts[n + m] = qs[n + m] = ps[n + m] = 0;
	for(int i = n + m - 1; i >= 0; i --) ps[i] = ps[i + 1] + (ce[i].second >= m ? 1 : -1);
	int lc = 0;
	for(int i = n + m - 1; i >= 0; i --) if(ps[i] < -1) {
		ts[i] = ts[i + 1]; qs[i] = qs[i + 1]; lc ++;
	} else if(ps[i] == -1) {
		ts[i] = ts[i + 1] + 1; qs[i] = qs[i + 1]; lc ++;
	} else if(ps[i] == 0) {
		ts[i] = ts[i + 1]; qs[i] = qs[i + 1] + 1;
	} else {
		ts[i] = ts[i + 1]; qs[i] = qs[i + 1];
	}
	
	rep(i, m) rep(j, hv[i].size()) {
		int ev = (sum[i] + hv[i].size() - 1) / hv[i].size(), od = (sum[i] - hv[i][j] + hv[i].size() - 2) / (hv[i].size() - 1);
		ev = lower_bound(ce, ce + n + m, MP(ev, -1)) - ce;
		od = lower_bound(ce, ce + n + m, MP(od, -1)) - ce;
		bool ok;
		if(lc) ok = ev > od && ts[od + 1] - ts[ev + 1] == lc;
		else ok = ev >= od || (od < n + m && qs[od + 1] == qs[ev + 1]);
		printf("%d", ok);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}