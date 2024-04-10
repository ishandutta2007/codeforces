#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
 
const int maxn = 100005;
const int mod = 1000000007;
int suf[maxn], sum[maxn], v[maxn], s[maxn];
int bin[maxn], pa[maxn], L[maxn], ans[maxn];
vector<pii> q[maxn];
int n, m, l, r, sz;
 
void merge(int a, int b) {
	if (a - L[a] > 40 && sum[b] > 0 || ((1ll * sum[b]) << (a - L[a] + 1)) + sum[a] > 2 * mod)
		sum[b] = 2 * mod;
	else
		sum[b] = (sum[b] << (a - L[a] + 1)) + sum[a];
	pa[a] = b; L[b] = L[a];
	v[b] = (v[a] + 1ll * bin[a - L[a] + 1] * v[b]) % mod;
}
 
int getpa(int x) {
	return pa[x] == x ? x : pa[x] = getpa(pa[x]);
}
 
int query(int l, int r) {
	int ans = 0, t = getpa(l);
	ans = (s[r] + mod - s[t]) % mod;
	ans = (ans + suf[l] - 1ll * bin[t-l+1] * suf[t+1] % mod) % mod;
	return (ans % mod + mod) % mod;
}
 
int main() {
	scanf("%d%d", &n, &m); bin[0] = 1;
	rep (i, 1, n) {
		scanf("%d", &v[i]);
		bin[i] = 2 * bin[i-1] % mod;
	}
	rep (i, 1, m) {
		scanf("%d%d", &l, &r);
		q[r].push_back(make_pair(l, i));
	}
	per (i, n, 1)
		suf[i] = (2ll * suf[i+1] + v[i]) % mod;
	rep (i, 1, n) {
		pa[i] = i; sum[i] = v[i]; L[i] = i;
		while (L[i] >= 2 && sum[i] >= 0) merge(L[i]-1, i);
		s[i] = (s[L[i]-1] + 2ll * v[i]) % mod;
		sz = q[i].size();
		rep (j, 0, sz - 1)
			ans[q[i][j].se] = query(q[i][j].fi, i);
	}	
	rep (i, 1, m) printf("%d ", ans[i]);
	return 0;
}