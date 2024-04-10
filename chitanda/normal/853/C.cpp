#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 200100, maxp = 200100 * 20;
int n, q, tot;
int rt[maxn];
int cnt[maxp], ls[maxp], rs[maxp];
int cal[9];

int insert(int rt, int l, int r, int x){
	int t = ++tot; ls[t] = ls[rt], rs[t] = rs[rt], cnt[t] = cnt[rt];
	++cnt[t];
	if(l == r) return t;
	int mid = (l + r) >> 1;
	if(x <= mid) ls[t] = insert(ls[t], l, mid, x);
	else rs[t] = insert(rs[t], mid + 1, r, x);
	return t;
}

int ask(int t, int l, int r, int x, int y){
	if(!t) return 0;
	if(x <= l && y >= r) return cnt[t];
	int mid = (l + r) >> 1;
	if(y <= mid) return ask(ls[t], l, mid, x, y);
	else if(x > mid) return ask(rs[t], mid + 1, r, x, y);
	else return ask(ls[t], l, mid, x, y) + ask(rs[t], mid + 1, r, x, y);
}

int main(){
	scanf("%d%d", &n ,&q);
	for(int i = 1, x; i <= n; ++i){
		scanf("%d", &x);
		rt[i] = insert(rt[i - 1], 1, n, x);
	}
	while(q--){
		static int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		cal[0] = y > 1 ? ask(rt[x - 1], 1, n, 1, y - 1) : 0;
		cal[2] = yy < n ? ask(rt[x - 1], 1, n, yy + 1, n) : 0;
		cal[1] = cnt[rt[x - 1]] - cal[0] - cal[2];
		
		cal[3] = y > 1 ? ask(rt[xx], 1, n, 1, y - 1) : 0;
		cal[5] = yy < n ? ask(rt[xx], 1, n, yy + 1, n) : 0;
		cal[4] = cnt[rt[xx]] - cal[3] - cal[5];
		
		cal[6] = y > 1 ? ask(rt[n], 1, n, 1, y - 1) : 0;
		cal[8] = yy < n ? ask(rt[n], 1, n, yy + 1, n) : 0;
		cal[7] = n - cal[6] - cal[8];
		
		cal[6] -= cal[3];
		cal[7] -= cal[4];
		cal[8] -= cal[5];
		cal[3] -= cal[0];
		cal[4] -= cal[1];
		cal[5] -= cal[2];
		
		ll ans = 1LL * n * (n - 1) / 2;
		for(int i = 0; i < 9; ++i)
			if(i != 4) ans -= (ll)cal[i] * (cal[i] - 1) / 2;
		ans -= (ll)cal[0] * cal[1];
		ans -= (ll)cal[0] * cal[2];
		ans -= (ll)cal[1] * cal[2];
		ans -= (ll)cal[0] * cal[3];
		ans -= (ll)cal[0] * cal[6];
		ans -= (ll)cal[3] * cal[6];
		ans -= (ll)cal[2] * cal[5];
		ans -= (ll)cal[2] * cal[8];
		ans -= (ll)cal[5] * cal[8];
		ans -= (ll)cal[6] * cal[7];
		ans -= (ll)cal[6] * cal[8];
		ans -= (ll)cal[7] * cal[8];
		
		printf("%lld\n", ans);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}