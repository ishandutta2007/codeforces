#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
ll D[303030], C[303030], X[303030];
ll M[22][22];
ll n, m;

int main()
{
	ll i, j, k, a, b;
	
	scanf("%lld%lld", &n, &m);
	
	for(i=1; i<=m; i++){
		scanf("%lld%lld", &a, &b);
		a --; b --;
		M[a][b] ++; M[b][a] ++;
	}
	
	for(i=0; i<(1<<n); i++){
		for(j=0; j<n; j++) if(i & 1 << j){
			X[i] ++;
			for(k=j+1; k<n; k++) if(i & 1 << k){
				if(M[j][k]) C[i] = 1;
			}
		}
	}
	
	D[0] = 1;
	
	for(i=1; i<(1<<n); i++){
		for(j=i; j; j=i&j-1) if(!C[j]){
			if(X[j] & 1) D[i] += D[i ^ j];
			else D[i] -= D[i ^ j];
		}
		D[i] = (D[i] % mod + mod) % mod;
	}
	
	printf("%lld\n", D[i - 1] * m % mod * (mod + 1 >> 1) % mod);
	
	return 0;
}