#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,ans;

int main()
{
	ll i;
	
	scanf("%lld",&n); n--;
	
	for(i=0;i<=50;i++){
		ans += (n / (1ull << i) - n / (2ull << i)) * (1ull << i);
	}
	
	printf("%lld\n",ans);
	
	return 0;
}