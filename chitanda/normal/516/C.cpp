#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
#define ls t << 1
#define rs t << 1 | 1
#define lss ls, l, mid
#define rss rs, mid + 1, r

const ll INF = 1LL << 60;
const int maxn = 100100;
pair<ll, int> tmax[2][maxn << 3];
int d[maxn << 1], h[maxn << 1];
ll s[maxn << 1];
int n, m;

void build(int t, int l, int r){
	if(l == r){
		tmax[0][t] = mkp(h[l] + s[l - 1], l);
		tmax[1][t] = mkp(h[l] - s[l - 1], l);
		return;
	}
	int mid = (l + r) >> 1;
	build(lss);
	build(rss);
	tmax[0][t] = max(tmax[0][ls], tmax[0][rs]);
	tmax[1][t] = max(tmax[1][ls], tmax[1][rs]);
}

pair<ll, int> ask(int t, int l, int r, int x, int y, bool k){
	if(x > y || y < l || x > r) return mkp(-INF, 0);
	if(x <= l && y >= r) return tmax[k][t];
	int mid = (l + r) >> 1;
	return max(ask(lss, x, y, k), ask(rss, x, y, k));
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", d + i);
	for(int i = 1; i <= n; ++i)
		scanf("%d", h + i), h[i] *= 2;
	for(int i = n + 1; i <= 2 * n; ++i)
		d[i] = d[i - n], h[i] = h[i - n];
	for(int i = 1; i <= 2 * n; ++i){
		s[i] = s[i - 1] + d[i];
	}
	build(1, 1, n << 1);
	for(int i = 1; i <= m; ++i){
		static int x, y, l, r;
		scanf("%d%d", &x, &y);
		if(x <= y) l = y + 1, r = x + n - 1;
		else l = y + 1, r = x - 1;
		auto tmp0 = ask(1, 1, n << 1, l, r, 0);
		auto tmp1 = ask(1, 1, n << 1, l, tmp0.se - 1, 1);
		auto tmp2 = ask(1, 1, n << 1, l, r, 1);
		auto tmp3 = ask(1, 1, n << 1, tmp2.se + 1, r, 0);
		
		ll ans = max(tmp0.fi + tmp1.fi, tmp2.fi + tmp3.fi);
		printf("%lld\n", ans);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}