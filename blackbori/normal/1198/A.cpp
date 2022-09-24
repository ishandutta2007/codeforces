#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> X;
ll A[404040];
ll n, k, ans;

int main()
{
	ll i, j, s;
	
	scanf("%lld%lld", &n, &k);

	k = k * 8 / n;
	
	if(k > 30) k = 1e9;
	else k = 1ll << k;
	
	for(i=1; i<=n; i++){
		scanf("%lld", A + i);
	}
	
	sort(A + 1, A + n + 1);
	
	for(i=1; i<=n; i=j){
		for(j=i; j<=n && A[i] == A[j]; j++);
		X.push_back(j - i);
	}
	
	ans = n;
	
	for(i=0, j=0, s=0; i<X.size(); i++){
		for(; j<X.size() && j < i + k; j++) s += X[j];
		ans = min(ans, n - s);
		s -= X[i];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}