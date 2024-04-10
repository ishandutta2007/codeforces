#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
char s[MN];
void solve () {
    scanf ("%s",s);
    int n = strlen(s);
    int ca = 0, cb = 0;
    for (int i = 0; i < n; i++) {
        ca += s[i] == 'A';
        cb += s[i] == 'B';
        if (cb > ca) {
            printf ("NO\n");
            return;
        }
    }
    if (s[0] == 'B' || s[n-1] == 'A') printf ("NO\n");
    else printf ("YES\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}