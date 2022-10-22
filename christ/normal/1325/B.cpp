#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e3+3, MOD = 1e9+7;
void solve () {
    int n;
    scanf ("%d",&n);
    vector<int> a(n);
    for (auto &au : a) scanf ("%d",&au);
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    printf ("%d\n",a.size());
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}