#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
void solve () {
    int n,a,b;
    scanf ("%d %d %d",&n,&a,&b);
    if (a > b) swap(a,b);
    printf ("%d %d\n",min(n,max(1,a+b+1-n)),min(n,a+b-1));
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}