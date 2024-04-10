#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+5, MOD = 998244353;
void solve () {
	long long n; int a,b;
	scanf ("%lld %d %d",&n,&a,&b);
	if (a*2 <= b) printf ("%lld\n",n*a);
	else printf ("%lld\n",(n/2)*b+(n&1)*a);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
     return 0;
}