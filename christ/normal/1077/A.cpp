#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int a[MN];
int color[MN];
void solve () {
	ll a,b,k;
	scanf ("%lld %lld %lld",&a,&b,&k);
	ll ret = (a-b)*(k/2);
	if (k&1) ret += a;
	printf ("%lld\n",ret);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}