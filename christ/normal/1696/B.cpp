#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
void solve () {
    int n; scanf ("%d",&n);
    bool allZero = true;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        allZero &= a[i] == 0;
    }
    if (allZero) {
        printf ("0\n");
        return;
    }
    int pre = 0, suf = n;
    while (a[pre] == 0) ++pre;
    while (a[suf] == 0) --suf;
    for (int i = pre; i <= suf; i++) if (a[i] == 0) {
        printf ("2\n");
        return;
    }
    printf ("1\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}