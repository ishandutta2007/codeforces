#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[101010];
bool chk[101010];
ll n, q, l, ans;

void add_new(ll p)
{
	chk[p] = 1;
	if(chk[p - 1] && chk[p + 1]) ans --;
	else if(!chk[p - 1] && !chk[p + 1]) ans ++;
}

int main()
{
	ll i, a, b;
	
	scanf("%lld%lld%lld", &n, &q, &l);
	
	for(i=1; i<=n; i++){
		scanf("%lld", A + i);
		if(A[i] > l) add_new(i);
	}
	
	for(; q--; ){
		scanf("%lld", &a);
		if(a == 0) printf("%lld\n", ans);
		else{
			scanf("%lld%lld", &a, &b);
			if(A[a] <= l && A[a] + b > l) add_new(a);
			A[a] += b;
		}
	}
	
	return 0;
}