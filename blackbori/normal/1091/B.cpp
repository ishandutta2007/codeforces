#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, sumx, sumy;

int main()
{
	ll i, x, y;
	
	scanf("%lld", &n);
	
	for(i=0; i<n+n; i++){
		scanf("%lld%lld", &x, &y);
		sumx += x; sumy += y;
	}
	
	printf("%lld %lld\n", sumx / n, sumy / n);
	
	return 0;
}