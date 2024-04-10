#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
	
using namespace std;
	
const int nax = 2e5 + 111;	
	
int n, m, ta, tb, k;
int a[nax];
int b[nax];

int main() {
	scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	FOR(i, n)
		scanf("%d", a + i);
	FOR(i, m)
		scanf("%d", b + i);
	ll ans = 0;
	if(k >= min(n, m)) {
		printf("-1");
		return 0;
	}
	int wsk = 1;
	for(int i = 1; i <= n; ++i) {
		int ile = i - 1;
		if(ile > k)
			continue;
		while(wsk <= m && a[i] + ta > b[wsk])
			wsk += 1;
		int r = (k - ile);
		if(wsk > m || wsk + r > m) {
			printf("-1\n");
			return 0;
		}
		ans = max(ans, (ll) tb + b[wsk + r]);
	}
	printf("%lld", ans);
	
	
	return 0;
}