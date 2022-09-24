#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[101010];
ll n, ans;

int main()
{
	ll i, s;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld", A + i);
	}
	
	sort(A, A + n);
	
	for(i=0, s=0; i<n-1; i++){
		if(A[i] == A[i + 1]) s ++;
	}
	
	if(s > 1 || (n >= 2 && A[0] == 0 && A[1] == 0)){
		printf("cslnb\n");
		return 0;
	}
	
	for(i=0; i<n-2; i++){
		if(A[i] == A[i + 1] - 1 && A[i + 1] == A[i + 2]){
			printf("cslnb\n");
			return 0;
		}
	}
	
	for(i=0; i<n; i++){
		ans += A[i] - i;
	}
	
	if(ans & 1) printf("sjfnb\n");
	else printf("cslnb\n");
	
	return 0;
}