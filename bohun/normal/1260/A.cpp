#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

int T;
int c, sum;
ll ans = 0;
int a[100005];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &c, &sum);
		ans = 0;
		for(int i = 0; i < c; ++i)
			a[i] = 0;
		int p = 0;
		while(sum > 0) {
			a[p++] += 1;
			sum -= 1;
			p %= c;
		}
		for(int i = 0; i < c; ++i)
			ans += 1ll * a[i] * a[i];
		printf("%lld\n", ans);
	}
		
		
					
	
	return 0;
}