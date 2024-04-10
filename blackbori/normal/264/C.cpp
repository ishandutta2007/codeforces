#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll D[101010], C[101010], K[101010];
ll n, q;
ll mx1, mx2, cnt1, cnt2;

int main()
{
	ll i, a, b, k;
	
	scanf("%lld%lld", &n, &q);
	
	for(i=1; i<=n; i++){
		scanf("%lld", D+i);
	}
	
	for(i=1; i<=n; i++){
		scanf("%lld", C+i);
	}
	
	for(; q--; ){
		scanf("%lld%lld", &a, &b);
		
		for(i=1; i<=n; i++) K[i] = -1e18;
		
		mx1 = 0, cnt1 = 1;
		mx2 = -1e18, cnt2 = n;
		
		for(i=1; i<=n; i++){
			if(K[C[i]] == mx1) cnt1 --;
			else if(K[C[i]] == mx2) cnt2 --;
			
			if(K[C[i]] != -1e18) k = max(K[C[i]], K[C[i]] + D[i] * a);
			else k = -1e18;
			if(cnt1) k = max(k, mx1 + D[i] * b);
			if(cnt2) k = max(k, mx2 + D[i] * b);
			
			if(k > K[C[i]]){
				if(k > mx1){
					if(cnt1 != 0){
						mx2 = mx1; cnt2 = cnt1;
					}
					mx1 = k; cnt1 = 1;
				}
				else if(k == mx1) cnt1 ++;
				else if(k > mx2){
					mx2 = k; cnt2 = 1;
				}
				else if(k == mx2) cnt2 ++;
				
				K[C[i]] = k;
				
				if(cnt2 == 0) cnt2 = 1;
			}
			else{
				if(K[C[i]] == mx1) cnt1 ++;
				else if(K[C[i]] == mx2) cnt2 ++;
			}
		}
		
		printf("%lld\n", mx1);
	}
	
	return 0;
}