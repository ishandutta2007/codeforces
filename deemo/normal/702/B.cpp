#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

ll a[MAXN];

int main(){
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll x = 1;
		for (int j = 0; j < 35; j++, x <<= 1){
			ans += upper_bound(a, a + n, x - a[i]) - lower_bound(a, a + n, x - a[i]);
			if (a[i] + a[i] == x)	ans--;
		}
	}
	printf("%lld\n", ans/2);
	return 0;
}