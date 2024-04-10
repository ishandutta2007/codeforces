#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll gcd(ll a,ll b)
{
	return a == 0 ? b : gcd(b%a, a);
}

int main()
{
	ll n,p,q,b,g;
	
	scanf("%lld",&n);
	
	for(;n--;){
		scanf("%lld%lld%lld",&p,&q,&b);
		
		if(p == 0){
			printf("Finite\n");
			continue;
		}
			
		g = gcd(p,q);
		q /= g;
		
		for(;q != 1;){
			g = gcd(q, b);
			if(g == 1) break;
			else for(;q%g==0;q/=g);
		}
		
		if(q == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	
	return 0;
}