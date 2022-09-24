#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segtree{
	ll T[606060], L[606060];
	
	void init(ll p, ll s, ll e)
	{
		if(s == e){
			T[p] = s * (s - 1) / 2;
		}
		else{
			init(p << 1, s, s + e >> 1);
			init(p << 1 | 1, (s + e >> 1) + 1, e);
			T[p] = min(T[p << 1], T[p << 1 | 1]);
		}
	}
	
	void addval(ll p, ll s, ll e, ll l, ll r, ll v)
	{
		if(r < s || e < l) return;
		if(l <= s && e <= r){
			T[p] += v; L[p] += v; return;
		}
		
		T[p << 1] += L[p]; L[p << 1] += L[p];
		T[p << 1 | 1] += L[p]; L[p << 1 | 1] += L[p];
		
		addval(p << 1, s, s + e >> 1, l, r, v);
		addval(p << 1 | 1, (s + e >> 1) + 1, e, l, r, v);
		
		T[p] = min(T[p << 1], T[p << 1 | 1]); L[p] = 0;
	}
	
	ll getid(ll p, ll s, ll e, ll v)
	{
		if(s == e) return s;
		
		v -= L[p];
		
		if(T[p << 1 | 1] <= v) return getid(p << 1 | 1, (s + e >> 1) + 1, e, v);
		else return getid(p << 1, s, s + e >> 1, v);
	}
};

segtree T;
ll S[202020], A[202020];
ll n;

int main()
{
	ll i;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++){
		scanf("%lld", S + i);
	}
	
	T.init(1, 1, n);
	
	for(i=n; i>=1; i--){
		A[i] = T.getid(1, 1, n, S[i]);
		T.addval(1, 1, n, A[i] + 1, n, -A[i]);
	}
	
	for(i=1; i<=n; i++){
		printf("%lld ", A[i]);
	}
	
	printf("\n");
	
	return 0;
}