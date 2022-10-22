#include <bits/stdc++.h>

#define ll long long

ll n, m;
int q;

ll solve(ll x, ll n){
	if (x & 1) return (x + 1) >> 1;
	return solve(x >> 1, n >> 1) + (n >> 1);
}

ll dfs(ll x, ll n){
	if (x <= (n - (m >> 1)) << 1){
		if (x & 1){
			return (x + 1) >> 1;
		}
		else{
			x = (x >> 1) + m - n;
		}
	}
	else{
		x = x - ((n - (m >> 1)) << 1);
	}
	return solve(x, m >> 1) + n - (m >> 1);
}

int main(){
	scanf("%I64d%d", &n, &q);
	for (m = 1; m <= n; m <<= 1);
	while (q --){
		ll x;
		scanf("%I64d", &x);
		printf("%I64d\n", dfs(x, n));
	}
	return 0;
}