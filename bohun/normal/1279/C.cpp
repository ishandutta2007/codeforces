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

int n, m;
int a[111111];
int b[111111];
int ind[111111];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			ind[a[i]] = i;
		}
		for(int i = 1; i <= m; ++i)
			scanf("%d", b + i);	
		ll ans = 0;
		int wsk = 0;
		for(int i = 1; i <= m; ++i) {
			int k = ind[b[i]];
			if(k < wsk) {
				ans++;
				continue;
			}
			ans += 2 * (k - i) + 1;
			wsk = k;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}