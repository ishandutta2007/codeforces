#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll k, d, t;

int main(){
	scanf("%I64d%I64d%I64d", &k, &d, &t);
	t *= 2;
	ll x = (k + d - 1) / d * d;
	ll y = k * 2 + (x - k);
	ll ans = t / y * x;
	t %= y;
	if(t <= 2 * k)
		if(t % 2)
			printf("%I64d.5\n", ans + t / 2);
		else
			printf("%I64d\n", ans + t / 2);
	else{
		t -= 2 * k;
		ans += k;
		printf("%I64d\n", ans + t);
	}
}