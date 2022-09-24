#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n, x;
	
	scanf("%lld", &n);
	
	for(; n --; ){
		scanf("%lld", &x);
		if(x <= 14) printf("NO\n");
		else if(1 <= x % 14 && x % 14 <= 6) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}