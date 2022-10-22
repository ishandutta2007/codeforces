#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, m, a[MAXN], sec[MAXN], tt[MAXN];
ll tl[MAXN], tr[MAXN], mx[MAXN], sum[MAXN];

pair<pair<ll, ll>, pair<ll, ll>> go(int b, int e){
	if (e - b == 1){
		b = sec[b];
		return {{tl[b], tr[b]}, {mx[b], sum[b]}};
	}

	int mid = b + e >> 1;
	auto f = go(b, mid), g = go(mid, e);
	auto ff = f;
	ff.S.S += g.S.S;
	ff.S.F = max({f.S.F, g.S.F, f.F.S + g.F.F});
	ff.F.F = max(f.F.F, f.S.S + g.F.F);
	ff.F.S = max(g.F.S, g.S.S + f.F.S);
	return ff;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		int sz;	scanf("%d", &sz);
		for (int j = 0; j < sz; j++)	scanf("%d", &a[j]);
		ll sm = 0;
		for (int j = 0; j < sz; j++)
			sm += a[j], tl[i] = max(tl[i], sm);
		sm = 0;
		for (int j = sz - 1; ~j; j--)
			sm += a[j], tr[i] = max(tr[i], sm);
		sum[i] = sm;
		sm = 0;
		for (int j = 0; j < sz; j++){
			sm += a[j];
			sm = max(sm, 0ll);
			mx[i] = max(mx[i], sm);
		}
		
		tt[i] = -2e9;
		for (int j = 0; j < sz; j++)
			tt[i] = max(tt[i], a[j]);
	}

	int tm = -2e9;
	for (int i = 0; i < m; i++){
		scanf("%d", &sec[i]), sec[i]--;
		tm = max(tm, tt[sec[i]]);
	}
	if (tm < 0){
		printf("%d\n", tm);
		return 0;
	}
	auto x = go(0, m);
	printf("%lld\n", x.S.F);
	return 0;
}