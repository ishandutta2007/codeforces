#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
pll P[101010];

int main()
{
	ll i, a, b, c, d;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++){
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		P[i] = pll(- (a + b + c + d), i);
	}
	
	sort(P+1, P+n+1);
	
	for(i=1; i<=n; i++){
		if(P[i].second == 1) break;
	}
	
	printf("%lld\n", i);
	
	return 0;
}