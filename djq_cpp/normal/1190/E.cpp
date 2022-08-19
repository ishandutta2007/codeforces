#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const double pi = 4 * atan(1);

int n, m;
int x[100005], y[100005];
int len, lp[100005], rp[100005];

int rs[400005];

vector<int> T[400005];
int dep[400005], dfn[400005], tot;
void dfs(int v, int cd)
{
	rep(i, T[v].size()) {
		int u = T[v][i];
		dfs(u, cd + 1);
	}
	dep[v] = cd;
	dfn[v] = tot ++;
}
bool check()
{
	rep(i, 2 * len) rs[i] = 2 * len;
	rs[2 * len] = 2 * len;
	rep(i, n) if(lp[i] <= rp[i]) {
		rs[lp[i]] = min(rs[lp[i]], rp[i]);
		rs[lp[i] + len] = min(rs[lp[i] + len], rp[i] + len);
	} else rs[lp[i]] = min(rs[lp[i]], rp[i] + len);
	
	for(int i = 2 * len - 1; i >= 0; i --) rs[i] = min(rs[i], rs[i + 1]);
	
	for(int i = 0; i <= 2 * len; i ++) T[i].clear();
	rep(i, 2 * len) T[min(rs[i] + 1, 2 * len)].push_back(i);
	tot = 0;
	dfs(2 * len, 0);
	
	rep(i, len) {
		int cj = i + 1, cans = dep[i] - dep[i + len];
		if(dfn[i] > dfn[i + len]) cans --;
		if(cans < m) return true; 
	}
	return false;
}

double dlp[100005], drp[100005];
vector<double> poss;
bool check(double dis)
{
	poss.clear();
	rep(i, n) {
		double cx = x[i], cy = y[i], cd = sqrt(cx * cx + cy * cy);
		cx /= cd;
		cy /= cd;
		double gmin = dis / cd;
		if(gmin >= 1) return false;
		double cdeg = atan2(cx, cy);
		double mind = asin(gmin), maxd = pi - mind;
		mind -= cdeg;
		maxd -= cdeg;
		if(mind < 0) mind += 2 * pi;
		if(maxd < 0) maxd += 2 * pi;
		dlp[i] = mind;
		drp[i] = maxd;
		poss.push_back(dlp[i]);
		poss.push_back(drp[i]);
	}
	sort(poss.begin(), poss.end());
	poss.resize(unique(poss.begin(), poss.end()) - poss.begin());
	len = poss.size();
	rep(i, n) {
		lp[i] = lower_bound(poss.begin(), poss.end(), dlp[i]) - poss.begin();
		rp[i] = lower_bound(poss.begin(), poss.end(), drp[i]) - poss.begin();
	}
	
	return check();
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d%d", &x[i], &y[i]);
	rep(i, n) if(x[i] == 0 && y[i] == 0) {
		printf("0.0\n");
		return 0;
	}
	
	double l = 0, r = 2e5;
	rep(i, n) r = min(r, sqrt(1LL * x[i] * x[i] + 1LL * y[i] * y[i]));
	rep(i, 80) {
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.8lf\n", r);
	return 0;
}