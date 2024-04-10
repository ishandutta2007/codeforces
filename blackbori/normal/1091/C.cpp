#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> V;
ll n;

int main()
{
	ll i;
	
	scanf("%lld", &n);
	
	for(i=1; i*i<=n; i++){
		if(n % i == 0){
			V.push_back(((n / i) * (n / i - 1) / 2) * i + n / i);
			V.push_back((i * (i - 1) / 2) * n / i + i);
		}
	}
	
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	
	for(ll &t: V){
		printf("%lld ", t);
	}
	
	printf("\n");
	
	return 0;
}