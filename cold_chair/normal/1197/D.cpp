#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;
 
const int N = 3e5 + 5;
 
int n, m, k;
ll a[N], b[N], ans;
multiset<ll> s;
 
int main() {
	scanf("%d %d %d", &n, &m, &k);
	fo(i, 1, n) scanf("%I64d", &a[i]), a[i] += a[i - 1];
	fo(i, 0, n) b[i] = -1e18;
	fo(i, 0, n) {
		if(i > 0) {
			ans = max(ans, a[i] + (*s.rbegin()));
		}
		int x = i % m;
		if(i >= m) {
			s.erase(s.find(b[x] - (ll) k * (i / m)));
		}
		b[x] = max(b[x], -a[i] + (ll) k * (i / m));
		s.insert(b[x] - (ll) k * (i / m + 1));
	}
	pp("%I64d\n", ans);
}