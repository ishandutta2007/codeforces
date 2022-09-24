#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll D[202020][2];
char S[202020];
ll n, a, b;

void tc()
{
	ll i;
	
	scanf("%lld%lld%lld%s", &n, &a, &b, S + 1);
	
	D[0][0] = b; D[0][1] = 1e18;
	
	for(i=1; i<=n; i++){
		if(S[i] == '0'){
			D[i][0] = min(D[i - 1][0] + a, D[i - 1][1] + a + a) + b;
			D[i][1] = min(D[i - 1][0] + a + a, D[i - 1][1] + a) + b + b;
		}
		else{
			D[i][0] = 1e18;
			D[i][1] = D[i - 1][1] + a + b + b;
		}
	}
	
	printf("%lld\n", D[n][0]);
}

int main()
{
	ll t;
	
	scanf("%lld", &t);
	
	for(; t--; ){
		tc();
	}
	
	return 0;
}