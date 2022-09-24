#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, ans;
ll A[202020];

int main()
{
	ll i;
	
	scanf("%lld", &n);
	
	for(i=0; i<n+n; i++){
		scanf("%lld", A+i);
	}
	
	sort(A, A+n+n);
	
	ans = (A[n-1] - A[0]) * (A[n+n-1] - A[n]);
	
	for(i=1; i<n; i++){
		ans = min(ans, (A[i+n-1] - A[i]) * (A[n+n-1] - A[0]));
	}
	
	printf("%lld\n", ans);
	
	return 0;
}