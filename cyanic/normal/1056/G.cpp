#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll, ll> x;
int n, m, s;
ll t, cnt;
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%lld", &s, &t);
	while(t) {
		int res = t % n;
		if(s > m) s -= res;
		else s += res;
		while(s > n) s -= n;
		while(s <= 0) s += n;
		t--;
		if (res > 233) continue;
   		ll ns = s * (ll)n + res;
   		if(x[ns]) t %= (x[ns] - t);
   		else x[ns] = t;
	}
	printf("%d\n", s);
	return 0;
}