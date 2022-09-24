#include <bits/stdc++.h>

typedef long long ll;

ll A[202020], S[202020];
ll n, k, p, ans;

int main()
{
	ll i, prev, j;
	
	scanf("%lld%lld", &n, &k);
	
	for(i=0;i<=n;i++){
		scanf("%lld", A+i);
		S[i] = A[i];
	}
	
	for(i=0;i<=n;i++){
		S[i] = S[i] + prev;
		if(S[i] & 1ll) break;
		prev = S[i] >> 1;
	}
	
	if(i > n) i = n;
	
	for(j=n;j>=i;j--){
		p = (p << 1) + S[j];
		if(p > 1e15 || p < -1e15) break;
	}
	
	for(j=i;j>=0 && j>=i-40;j--){
		if(p > 1e15 || p < -1e15) break;
		if(A[j] - p <= k && -k <= A[j] - p && (j != n || A[j] != p)) ans ++;
		p <<= 1;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}