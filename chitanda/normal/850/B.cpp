#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, x, y;
int a[500100];
int cnt[2000100];
ll sum[2000100];

inline int get(int l, int r){
	return cnt[r] - cnt[l - 1];
}

inline ll All(int l, int r){
	return sum[r] - sum[l - 1];
}

int main(){
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), cnt[a[i]]++;
	for(int i = 1; i <= 2000000; ++i){
		sum[i] = sum[i - 1] + (ll)cnt[i] * i;
		cnt[i] += cnt[i - 1];
	}
	
	int lim = x / y + 1;

	ll ans = 1LL << 60;
	for(int d = 2; d <= 1000000; ++d){
		int l = min(lim, d);

		ll res = 0;
		for(int i = 1; i <= 1000000; i += d)
			res += (ll)get(i, i + d - l - 1) * x + y * ((ll)get(i + d - l, i + d - 1) * (i + d - 1) - All(i + d - l, i + d - 1));
		
		ans = min(ans, res);
	}

	printf("%lld\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}