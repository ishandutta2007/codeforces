#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, q;
LL a[3][500005];
vector<pair<int, LL> > G[500005];
LL fr[500005], dp[500005];

LL tmp[500005];
void solve(int l, int r, vector<pair<PII, LL> > vec, LL hc)
{
	if(l == r) return;
	
	vector<pair<PII, LL> > nv;
	LL nhc = hc;
	rep(i, vec.size()) {
		if(vec[i].first.first <= l && vec[i].first.second >= r) nhc = min(nhc, vec[i].second);
		else if(vec[i].first.second < l || vec[i].first.first > r) continue;
		else nv.push_back(MP(MP(max(vec[i].first.first, l), min(vec[i].first.second, r)), vec[i].second));
	}
	
	int mid = (l + r) >> 1;
	solve(l, mid, nv, nhc);
	
	nv.push_back(MP(MP(l, r), nhc));
	for(int i = l; i <= r; i ++) tmp[i] = INF;
	for(int i = l; i <= mid; i ++) tmp[i] = min(dp[i], fr[i]);
	for(int i = mid - 1; i >= l; i --) tmp[i] = min(tmp[i], tmp[i + 1]);
	rep(i, nv.size()) if(nv[i].first.second > mid && nv[i].first.first <= mid)
	tmp[nv[i].first.second] = min(tmp[nv[i].first.second], tmp[nv[i].first.first] + nv[i].second);
	for(int i = r - 1; i >= mid + 1; i --) tmp[i] = min(tmp[i], tmp[i + 1]);
	for(int i = mid + 1; i <= r; i ++) dp[i] = min(dp[i], tmp[i]);
	nv.pop_back();
	
	solve(mid + 1, r, nv, nhc);
}

int main()
{
	scanf("%d%d", &n, &q);
	rep(i, 3) rep1(j, n) {
		scanf("%lld", &a[i][j]); a[i][j] += 1 << 30;
	}
	rep(i, 3) rep1(j, n) a[i][j] += a[i][j - 1];
	
	vector<pair<PII, LL> > vec;
	rep(i, q) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		vec.push_back(MP(MP(l, r + 1), k));
	}
	
	rep1(i, n) fr[i] = a[0][n] - a[0][i] + a[1][i - 1];
	fr[n + 1] = INF;
	rep1(i, n + 1) dp[i] = INF;
	solve(1, n + 1, vec, INF);
	
	LL ans = INF;
	rep1(i, n) ans = min(ans, dp[i + 1] + a[2][i - 1] + a[1][n] - a[1][i]);
	rep(i, 3) ans -= a[i][n];
	ans *= -1;
	ans -= (2LL + n) << 30;
	printf("%lld\n", ans);
	return 0;
}