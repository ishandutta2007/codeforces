#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve () {
	ll a,b,n,s;
	scanf ("%lld %lld %lld %lld",&a,&b,&n,&s);
	if (a * n + b < s) return (void) printf ("no\n");
	ll cur = n * min(a,s/n);
	cur += min(b,s-cur);
	if (cur != s) printf ("no\n");else printf ("yes\n");
}
int main() {
    int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}