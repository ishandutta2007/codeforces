#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

deque <ll> D;
ll A[303030], B[303030];
ll n;

int main()
{
	ll q, a, x, i;
	
	scanf("%lld%lld", &n, &q);
	
	for(i=1; i<=n; i++){
		scanf("%lld", &a);
		D.push_back(a);
	}
	
	for(i=1; i<=n+n; i++){
		A[i] = D.front(); D.pop_front();
		B[i] = D.front(); D.pop_front();
		if(A[i] > B[i]) D.push_front(A[i]), D.push_back(B[i]);
		else D.push_front(B[i]), D.push_back(A[i]);
	}
	
	for(; q--; ){
		scanf("%lld", &x);
		if(x <= n) printf("%lld %lld\n", A[x], B[x]);
		else printf("%lld %lld\n", A[n + (x - n) % (n - 1)], B[n + (x - n) % (n - 1)]);
	}
	
	return 0;
}