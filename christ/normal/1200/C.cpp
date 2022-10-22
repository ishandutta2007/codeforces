#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+2;
typedef long long ll;
int main() {
    ll a,b; int q;
    scanf ("%lld %lld %d",&a,&b,&q);
    ll gcd = __gcd(a,b), adiv = a/gcd, bdiv = b/gcd;
    while (q--) {
        ll sx,sy,ex,ey;
        scanf ("%lld %lld %lld %lld",&sx,&sy,&ex,&ey);
        sy--; ey--;
        ll sblock = sx == 1 ? sy/adiv : sy/bdiv, eblock = ex == 1 ? ey/adiv : ey/bdiv;
        printf (sblock == eblock ? "YES\n" : "NO\n");
    }

    return 0;
}