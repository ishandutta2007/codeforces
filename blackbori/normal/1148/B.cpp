#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[202020], B[202020];
ll n, m, a, b, k, ans;

int main()
{
	ll i, j;
	
	scanf("%lld%lld%lld%lld%lld", &n, &m, &a, &b, &k);
	
	for(i=0; i<n; i++){
		scanf("%lld", A + i);
	}
	
	for(i=0; i<m; i++){
		scanf("%lld", B + i);
		B[i] -= a;
	}
	
	if(n <= k || m <= k){
		printf("-1\n");
		return 0;
	}
	
	for(i=0, j=0; i<=k; i++){
		for(; j<m && B[j] < A[i]; j++);
		if(j + (k - i) >= m){
			printf("-1\n");
			return 0;
		}
		else ans = max(ans, B[j + k - i] + a + b);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}