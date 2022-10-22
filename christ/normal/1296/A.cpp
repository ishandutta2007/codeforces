#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve () {
    int n;
    scanf ("%d",&n);
    vector<int> a(n);
    int ce = 0, sum = 0;
    for (auto &au : a) scanf ("%d",&au), ce += au&1, sum += au;
    if ((ce != 0 && ce != n) || (sum&1)) return (void) printf ("YES\n");
    printf ("NO\n");
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}