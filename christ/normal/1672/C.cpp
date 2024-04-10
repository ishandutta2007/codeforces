#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
char s[MN];
void solve () {
    int n; scanf ("%d",&n);
    vector<int> v(n);
    for (int &i : v) scanf ("%d",&i);
    int st = 0;
    for (int i = 0; i + 1 < n; i++) if (v[i] == v[i+1]) ++st;
    if (st <= 1) {
        printf ("0\n");
        return;
    }
    int f = INT_MAX, l = INT_MIN;
    for (int i = 0; i + 1 < n; i++) {
        if (v[i] == v[i+1]) {
            f = min(f,i);
            l = max(l,i);
        }
    }
    printf ("%d\n", max(1,l - f - 1));
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}