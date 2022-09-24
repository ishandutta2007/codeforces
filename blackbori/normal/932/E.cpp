#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

ll K[5050], D[5050];
int T[5050][5050];
ll n,k,ans;

ll mypow(ll a,ll b)
{
	if(!b) return 1;
	ll ret = mypow(a,b>>1);
	ret *= ret; ret %= mod;
	return ret * (b&1? a:1) % mod;
}

int main()
{
	ll i,j,s;
	
	scanf("%lld%lld",&n,&k);
	
	if(n < k){
		T[0][0] = 1;
		for(i=1;i<=n;i++){
			T[i][0] = 1;
			for(j=1;j<=i;j++) T[i][j] = ((ll)T[i-1][j] + (ll)T[i-1][j-1]) % mod;
		}
		
		for(i=0;i<=n;i++){
			ans = (ans + (ll)T[n][i] * mypow(i,k)) % mod;
		}
		
		printf("%lld\n",ans);
		
		return 0;
	}
	
	T[0][0] = s = 1;
	
	for(i=1;i<=k;i++){
		s = s * (n-i+1) % mod;
		K[i] = (s * mypow(2,n-i)) % mod;
		
		for(j=0;j<i;j++){
			T[i][j] = (((ll)T[i][j] - (i-1) * (ll)T[i-1][j]) % mod + mod) % mod;
			T[i][j+1] = ((ll)T[i][j+1] + (ll)T[i-1][j]) % mod;
		}
	}
	
	D[k] = -1;
	
	for(i=k;i>=0;i--){
		s = -D[i]; ans = ((ans + s * K[i]) % mod + mod) % mod;
		for(j=0;j<=i;j++) D[j] = ((D[j] + s * (ll)T[i][j]) % mod + mod) % mod;
	}
	
	printf("%lld\n",ans);
	
	return 0;
}