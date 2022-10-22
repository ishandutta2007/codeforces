#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int freq[10005],area;
int main() {
    int n,cnt = 0;
    ll a,gcd = 0;
    scanf ("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf ("%lld",&a);
        gcd = __gcd(gcd,a);
    }
    for (int i = 1; i * 1LL * i <= gcd; i++) {
        if (gcd % i == 0) {
            ++cnt;
            if (gcd/i != i) ++cnt;
        }
    }
    printf ("%d\n",cnt);
    return 0;
}