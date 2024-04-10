#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cout << #x << " = " << x << endl
 
using namespace std;

const int nax = 1e6 + 111;

int n;
ll a[nax];
ll ans;

int j, x, y;

int main() {
	srand(2137);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	while(clock() <= 3.5 * CLOCKS_PER_SEC) {
		int r = ((rand() << 5) ^ rand()) % n + 1;
		vector <ll> divisors;
		for(j = 1; (ll) j * j <= a[r]; ++j) {
			if(!(a[r] % j)) {
				divisors.pb(j);
				if(j * j != a[r])
					divisors.pb(a[r] / j);
			}
		}
		
		
		sort(divisors.begin(), divisors.end());
		int SIZ = ss(divisors);
		static int ile[10000];
		memset(ile, 0, sizeof(ile));
		for(j = 1; j <= n; ++j)
			ile[lower_bound(divisors.begin(), divisors.end(), __gcd(a[r], a[j])) - divisors.begin()] += 1;
		for(x = 0; x < SIZ; ++x) {
			for(y = x + 1; y < SIZ; ++y) 
				if(!(divisors[y] % divisors[x]))
					ile[x] += ile[y];
			if(ile[x] * 2 >= n) 
				ans = max(ans, divisors[x]);
		}
	}
	printf("%lld", ans);
	
		
	
	
	return 0;
}