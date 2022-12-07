#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
ll k;
int a[110];

ll check(ll d){
	ll res = 0;
	for(int i = 1; i <= n; ++i)
		res += (d - a[i] % d) % d;
	return res;
}

int main(){
	scanf("%d%lld", &n, &k);
	vector<int> q;
	ll sum = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		for(int j = 1, k = 1; j <= a[i]; j = k + 1){
			k = a[i] / (a[i] / j);
			if(a[i] % k == 0 && k > j) q.pb(a[i] / k);
			q.pb(ceil(1. * a[i] / j));
		}
		sum += a[i];
	}
	sort(all(q));
	q.erase(unique(all(q)), q.end());
	int m = q.size(), la = -1;
	for(int i = 0; i < m; ++i){
		if(check(q[i]) <= k) la = i;
	}
	ll l = q[la], r = la < m - 1 ? q[la + 1] : sum + k + 10;
	while(l + 1 < r){
		ll d = (l + r) >> 1;
		if(check(d) <= k) l = d;
		else r = d;
	}
	printf("%lld\n", l);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}