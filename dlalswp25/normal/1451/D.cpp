#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll d, k;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%lld%lld", &d, &k);
		ll x = 0, y = 0;
		int z = 0;
		while(1) {
			if(z & 1) {
				if(x * x + (y + k) * (y + k) > d * d) break;
				y += k;
			}
			else {
				if((x + k) * (x + k) + y * y > d * d) break;
				x += k;
			}
			z++;
		}
		puts(z & 1 ? "Ashish" : "Utkarsh");
	}
	return 0;
}