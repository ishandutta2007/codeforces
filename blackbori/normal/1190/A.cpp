#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[101010];
ll n, m, k, ans;

int main()
{
	ll i, j;
	
	scanf("%lld%lld%lld", &n, &m, &k);
	
	for(i=1; i<=m; i++){
		scanf("%lld", A + i);
	}
	
	for(i=1; i<=m; i=j){
		for(j=i; (A[i] - i) / k == (A[j] - i) / k; j++);
		ans ++;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}