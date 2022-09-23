#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll a, b, x; scanf("%lld%lld%lld", &a, &b, &x);
		bool ok = false;
		while(a && b) {
			if(a > b) swap(a, b);
			if(a == x || b == x) { puts("YES"); ok = true; break; }
			if(a < x && b < x) { puts("NO"); ok = true; break; }
			if(b % a == x % a) { puts("YES"); ok = true; break; }
			b %= a;
		}
		if(!ok) puts("NO");
	}
	return 0;
}