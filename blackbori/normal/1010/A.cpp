#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll A[1010], B[1010];
ll n, k;
ld ans;

ld calc(ll t, ll w, ld f)
{
	return f + (w + f) / (t - 1);
}

void die()
{
	printf("-1\n");
	exit(0);
}

int main()
{
	ll i;
	
	scanf("%lld%lld", &n, &k);
	
	for(i=1; i<=n; i++){
		scanf("%lld", A+i);
		if(A[i] <= 1) die();
	}
	
	for(i=0; i<n; i++){
		scanf("%lld", B+i);
		if(B[i] <= 1) die();
	}
	
	B[n] = B[0];
	
	ans = 0;
	
	for(i=n; i>=1; i--){
		ans = calc(B[i], k, ans);
		ans = calc(A[i], k, ans);
	}
	
	printf("%.20lf\n", (double)ans);
	
	return 0;
}