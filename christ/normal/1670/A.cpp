#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
void solve () {
    int n; scanf ("%d",&n);
    int cntNeg = 0;
    vector<int> a(n);
    for (int &i : a) {
        scanf ("%d",&i);
        cntNeg += i < 0;
    }
    for (int i = 0; i < cntNeg; i++) a[i] = -abs(a[i]);
    for (int i = cntNeg; i < n; i++) a[i] = abs(a[i]);
    if (is_sorted(a.begin(),a.end())) printf ("YES\n");
    else printf ("NO\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}