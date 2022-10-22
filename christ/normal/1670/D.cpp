#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
vector<int> can;
void solve () {
    int n; scanf ("%d",&n);
    printf ("%d\n",(int)(lower_bound(can.begin(),can.end(),n) - can.begin()));
}
int main () {
    int ans = 0, a = 0, b = 0, c = 0;
    int p = 0;
    can.push_back(0);
    while (ans < MOD) {
        if (p % 3 == 0) {
            ++a;
            ans += 2 * (b + c);
        } else if (p % 3 == 1) {
            ++b;
            ans += 2 * (a + c);
        } else {
            ++c;
            ans += 2 * (a + b);
        }
        ++p;
        can.push_back(ans);
    }
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}