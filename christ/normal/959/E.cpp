#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 53;
int main () {
	ll n;
	scanf ("%lld",&n);
	--n;
	ll ans = 0;
	for (int i = 0; (1LL << i) <= n; i++) ans += (1LL<<i)*((n+(1LL<<i))/(1LL<<(i+1)));
	printf ("%lld\n",ans);
    return 0;
}