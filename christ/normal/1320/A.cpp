#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main() {
    int n;
    scanf ("%d",&n);
    map<int,ll> best; ll ret = 0;
    for (int i = 1; i <= n; i++) {
        int a; scanf ("%d",&a);
        ret = max(ret,best[i-a] += a);
    }
    printf ("%lld\n",ret);
    return 0;
}