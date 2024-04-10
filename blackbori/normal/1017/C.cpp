#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, sz;

int main()
{
	ll i, l, r;
	
	scanf("%lld", &n);
	
	for(sz=1; sz*sz<n; sz++);
	
	l = 1; r = sz;
	for(; ; ){
		for(i=r; i>=l; i--) printf("%lld ", i);
		if(r == n) break;
		l = r + 1; r = min(n, l - 1 + sz);
	}
	
	printf("\n");
		
	return 0;
}