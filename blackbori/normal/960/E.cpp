#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9+7;

vector <ll> V[202020];
ll A[202020], B[202020], P[202020], T[202020];
ll n,ans;

ll dfs1(ll p,ll r)
{
	ll a,b;
	a = 1, b = 0; T[p] = 1;
	
	for(int t: V[p]) if(t != r){
		T[p] += dfs1(t,p);
		a = (a + B[t]) % mod; b = (b + A[t]) % mod;
	}
	
	ans = (ans + P[p] * (n - T[p])) % mod;
	
	for(int t: V[p]) if(t != r){
		ans = (ans + P[p] * (B[t] - A[t]) % mod * (n - T[t])) % mod;
//		printf("%lld : %lld\n",p,(B[t] - A[t]) * (n - T[t]));
	}
	
	A[p] = a, B[p] = b;
	
	return T[p];
}

ll dfs2(ll p,ll r,ll a,ll b)
{
	for(int t: V[p]) if(t != r){
		dfs2(t,p,(b + B[p] - A[t]) % mod, (a + A[p] - B[t]) % mod);
	}
	ans = (ans + P[p] * (a+1-b) % mod * T[p]) % mod;
	
//	printf("%lld %lld %lld\n",p,a,b);
	
//	printf("%lld : %lld\n",p,(a+1-b) % mod * T[p]);
	
	return 0;
}

int main()
{
	ll a,b,i;
	
	scanf("%lld",&n);
	
	for(i=1;i<=n;i++) scanf("%lld",P+i);
	
	for(i=1;i<n;i++){
		scanf("%lld%lld",&a,&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	dfs1(1,0);
	dfs2(1,0,0,0);
	
	printf("%lld\n",(ans % mod + mod) % mod);
	
	return 0;
}