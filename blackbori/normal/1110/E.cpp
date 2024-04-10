#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> X, Y;
ll A[101010], B[101010];
ll n;

int main()
{
	ll i;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++){
		scanf("%lld", A + i);
		if(i > 1) X.push_back(A[i] - A[i - 1]);
	}
	
	for(i=1; i<=n; i++){
		scanf("%lld", B + i);
		if(i > 1) Y.push_back(B[i] - B[i - 1]);
	}
	
	if(A[1] != B[1]) printf("No\n");
	else{
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		
		for(i=0; i<n-1; i++){
			if(X[i] != Y[i]) break;
		}
		
		if(i < n - 1) printf("No\n");
		else printf("Yes\n");
	}
	
	return 0;
}