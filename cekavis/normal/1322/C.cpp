#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll

const int N = 500005;
int n, m, T;
ull b[N];
pair<ull,ll> a[N];
int main() {
	mt19937_64 rng(chrono::system_clock().now().time_since_epoch().count());
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) scanf("%lld", &a[i].second), a[i].first=0;
		for(int i=1; i<=n; ++i) b[i]=rng();
		for(int i=1, x, y; i<=m; ++i) scanf("%d%d", &x, &y), a[y].first^=b[x];
		sort(a+1, a+n+1);
		ll ans=0;
		for(int i=1; i<=n+1; ++i)
			if(a[i].first==a[i-1].first) a[i].second+=a[i-1].second;
			else if(a[i-1].first) ans=__gcd(ans, a[i-1].second);
		printf("%lld\n", ans);
	}
	return 0;
}