#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

ll a[111111];
ll p[111111];
multiset <pair<ll, ll>> sec;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		sec.clear();
		int n, s;
		scanf("%d %d", &n, &s);
		int naj = 0;
		int cu = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			p[i] = p[i - 1] + a[i];
			sec.insert(mp(p[i], i));
			if(p[i] <= s)
				naj = i;
		}
		for(int i = 0; i < n; ++i) {
			if(p[i] > s) continue;
			auto it = sec.upper_bound({1ll * s + a[i + 1], 111111111});
			--it;
			if(naj < it->se - 1) {
				naj = it->se - 1;
				cu = i + 1;
			}
		}
		printf("%d\n", cu);
			
		
	}
	
	return 0;
}