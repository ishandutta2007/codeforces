#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e6+2, MOD = 1e9+7, LOG = 15, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
void solve () {
	vector<int> a(3); int n;
	scanf ("%d %d %d %d",&a[0],&a[1],&a[2],&n);
	sort(all(a));
	int need = a[2] - a[1] + a[2] - a[0];
	if (n < need) return (void) printf ("NO\n");
	else if (n%3 != need%3) return (void) printf ("NO\n");
	printf ("YES\n");
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}