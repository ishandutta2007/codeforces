#include<bits/stdc++.h>
#define ll long long

ll calc(ll x, ll y){
	return x * (x + 1) * (y + 1) + y * (y + 1) * (x + 1) >> 1;
}

int main(){
	int m, b;
	scanf("%d%d", &m, &b);
	ll ans = 0;
	for (int i = 0; i <= m * b; ++ i){
		ans = std::max(ans, calc(i, (m * b - i) / m));
	}
	return printf("%I64d\n", ans), 0;
}