#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll D[5050][111], C[5050], K[5050], W[111];
ll n, m, q;

int main()
{
	char str[111];
	ll i, j, v, k;
	
	scanf("%lld%lld%lld", &n, &m, &q);
	
	for(i=0; i<n; i++){
		scanf("%lld", W+(n-i-1));
	}
	
	for(i=0; i<(1<<n); i++){
		for(j=0; j<n; j++){
			if(i & (1 << j)) continue;
			else C[i] += W[j];
		}
	}
	
	for(i=0; i<m; i++){
		scanf("%s", str);
		
		v = 0;
		for(j=0; j<n; j++){
			v = v * 2 + (str[j] == '1');
		}
		
		K[v] ++;
	}
	
	for(i=0; i<(1<<n); i++){
		for(j=0; j<(1<<n); j++){
			if(C[i ^ j] <= 100) D[i][C[i ^ j]] += K[j];
		}
		for(j=1; j<=100; j++) D[i][j] += D[i][j-1];
	}
	
	for(i=0; i<q; i++){
		scanf("%s%lld", str, &k);
		
		v = 0;
		for(j=0; j<n; j++){
			v = v * 2 + (str[j] == '1');
		}
		
		printf("%lld\n", D[v][k]);
	}
	
	return 0;
}