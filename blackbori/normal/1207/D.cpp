#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

const ll mod = 998244353;

ll F[303030];
pll S[303030];
ll n, ans;

int main()
{
	ll i, j, s;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld%lld", &S[i].first, &S[i].second);
	}
	
	F[0] = 1;
	
	for(i=1; i<=n; i++){
		F[i] = F[i - 1] * i % mod;
	}
	
	ans = F[n];
	
	sort(S, S + n);
	
	for(i=0, s=1; i<n; i=j){
		for(j=i; S[i].first == S[j].first; j++);
		s = s * F[j - i] % mod;
	}
	
	ans = (ans - s + mod) % mod;
	
	for(i=0; i<n; i++){
		swap(S[i].first, S[i].second);
	}
	
	sort(S, S + n);
	
	for(i=0, s=1; i<n; i=j){
		for(j=i; S[i].first == S[j].first; j++);
		s = s * F[j - i] % mod;
	}
	
	ans = (ans - s + mod) % mod;
	
	for(i=1; i<n; i++){
		if(S[i - 1].second > S[i].second) break;
	}
	
	if(i == n){
		for(i=0, s=1; i<n; i=j){
			for(j=i; S[i] == S[j]; j++);
			s = s * F[j - i] % mod;
		}
		ans = (ans + s) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}