#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve () {
	ll a,b,c;
	scanf ("%lld %lld %lld",&a,&b,&c);
	printf ("%lld\n",(a+b+c)/2);
}
int main() {
    int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}