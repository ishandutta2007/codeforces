#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map <ll, ll> M;
ll A[202020], D[202020];
ll n, q, s;

void rem(ll k) { if(D[k] -- <= A[k]) s ++; }
void add(ll k) { if(D[k] ++ < A[k]) s --; }

int main()
{
	ll i, a, b, c, x;
	
	scanf("%lld", &n);
	
	for(i = 1; i <= n; i ++){
		scanf("%lld", A + i);
		s += A[i];
	}
	
	scanf("%lld", &q);
	
	for(; q --; ){	
		scanf("%lld%lld%lld", &a, &b, &c);
		x = b * n + a;
		if(M[x] != 0) rem(M[x]);
		M[x] = c; if(c) add(c);
		printf("%lld\n", s);
	}
		
	return 0;
}