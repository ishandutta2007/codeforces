#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k, g;

ll gcd(ll a, ll b)
{
	return a? gcd(b % a, a) : b;
}

int main()
{
	ll i, a;
	
	scanf("%lld%lld", &n, &k);
	
	g = k;
	
	for(i=1; i<=n; i++){
		scanf("%lld", &a);
		g = gcd(g, a);
	}
	
	if(g == k){
		printf("1\n0\n");
	}
	else{
		printf("%lld\n", k / g);
		for(i=0; i<k; i+=g) printf("%lld ", i);
		printf("\n");
	}
	
	return 0;
}