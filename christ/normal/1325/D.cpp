#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main() {
    ll a,b;
    scanf ("%lld %lld",&a,&b);
    if (!a && !b) return !printf ("0\n");
    if (a == b) return !printf ("1\n%lld\n",a);
    if ((a&1) != (b&1) || b < a) return !printf ("-1\n");
    ll x = 0, y = 0;
    for (int i = 60; i >= 0; i--) if (a>>i&1) x |= (1LL << i);
    ll sum = x;
    for (int i = 60; i >= 0; i--) if (!(a>>i&1) && (sum + (1LL << (i+1))) <= b) sum += (1LL << (i+1)), x |= 1LL << i, y |= 1LL << i;
    if (x+y == b) return !printf ("2\n%lld %lld\n",x,y);
    printf ("3\n%lld %lld %lld\n",a,(b-a)/2,(b-a)/2);
    return 0;
}