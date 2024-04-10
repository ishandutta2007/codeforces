#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e3+3, MOD = 1e9+7;
void solve() {
    int n,sum=0;
    scanf ("%d",&n);
    vector<int> a(n);
    for (auto &au : a) scanf ("%d",&au);
    int go = a[0]&1;
    for (int i = 1; i < n; i++) if ((a[i]&1) != go) return (void) printf ("NO\n");
    printf ("YES\n");
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}