#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e3+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int dp[MN][MN];
int seg[MN<<1];
int n;
void build (int d) {
	for (int i = n; i < (n << 1); i++) seg[i] = dp[d][i-n]-(i-n+1);
	for (int i = n-1; i > 0; i--) seg[i] = max(seg[i<<1],seg[i<<1|1]);
}
int query (int l, int r) {
	int ret = INT_MIN;
	for (l += n-1, r += n; l < r; l>>=1, r>>=1) {
		if (l&1) ret = max(ret,seg[l++]);
		if (r&1) ret = max(ret,seg[--r]);
	}
	return ret;
}
int main() {
    int k;
	scanf ("%d %d",&n,&k);
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	sort(a.begin()+1,a.end());
	build(0);
	for (int teams = 1; teams <= k; teams++) {
		for (int i = 1; i <= n; i++) {
			dp[teams][i] = dp[teams][i-1];
			int it = lower_bound(a.begin()+1,a.end(),a[i]-5)-a.begin();
			dp[teams][i] = max(dp[teams][i],query(it,i)+i+1);
		}
		build(teams);
	}
	printf ("%d\n",dp[k][n]);
    return 0;
}