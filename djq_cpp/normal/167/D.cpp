#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 9;
 
int n, k, q, a, b, c, d, x[100005], y[100005];
vector<int> xs;
int val[100005], par[100005], ch[100005][2];
PII dp[100005], cdp[100005];
int sta[100005], siz;
PII tmerge(const PII& ldp, const PII& rdp)
{
	return MP(max(ldp.second + rdp.first, ldp.first + rdp.second) + 1, ldp.first + rdp.first);
}
void dfs(int v)
{
	if(v == -1) return;
	dfs(ch[v][0]); dfs(ch[v][1]);
	dp[v] = tmerge(ch[v][0] == -1 ? MP(0, -1) : dp[ch[v][0]], ch[v][1] == -1 ? MP(0, -1) : dp[ch[v][1]]);
}
 
int main()
{
	scanf("%d%d", &n, &k);
	rep(i, k) scanf("%d%d", &x[i], &y[i]);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for(int i = k; i < n; i ++) {
		x[i] = (1ULL * a * x[i - 1] + b) % MOD;
		y[i] = (1ULL * c * y[i - 1] + d) % MOD;
	}
	rep(i, n) xs.push_back(x[i]);
	sort(xs.begin(), xs.end());
	rep(i, n) val[lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin()] = y[i];
	
	rep(i, n) ch[i][0] = ch[i][1] = -1;
	rep(i, n) {
		while(siz > 0 && val[sta[siz - 1]] < val[i]) {
			siz --;
			int v = siz > 0 && val[sta[siz - 1]] < val[i] ? sta[siz - 1] : i;
			par[sta[siz]] = v; ch[v][v != i] = sta[siz];
		}
		sta[siz ++] = i;
	}
	for(int i = siz - 1; i >= 1; i --) {
		int v = sta[i - 1];
		par[sta[i]] = v; ch[v][1] = sta[i];
	}
	dfs(sta[0]);
	par[sta[0]] = n; ch[n][0] = sta[0]; val[n] = MOD;
	rep(i, n) cdp[i] = dp[i];
	
	scanf("%d", &q);
	rep(i, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		l = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
		r = upper_bound(xs.begin(), xs.end(), r) - xs.begin() - 1;
		if(l > r) printf("0\n");
		else {
			int u = l == 0 ? n : l - 1, v = r + 1;
			cdp[u] = ch[u][1] == -1 ? MP(0, -1) : dp[ch[u][1]];
			cdp[v] = ch[v][0] == -1 ? MP(0, -1) : dp[ch[v][0]];
			while(u != v) {
				if(val[u] > val[v]) swap(u, v);
				u = par[u];
				if(u < l) cdp[u] = cdp[ch[u][1]];
				else if(u > r) cdp[u] = cdp[ch[u][0]];
				else cdp[u] = tmerge(ch[u][0] == -1 ? MP(0, -1) : cdp[ch[u][0]], ch[u][1] == -1 ? MP(0, -1) : cdp[ch[u][1]]);
			}
			printf("%d\n", cdp[u].first);
			u = l == 0 ? n : l - 1; v = r + 1;
			cdp[u] = dp[u]; cdp[v] = dp[v];
			while(u != v) {
				if(val[u] > val[v]) swap(u, v);
				u = par[u]; cdp[u] = dp[u];
			}
		}
	}
	return 0;
}