#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
char s[MN];
void solve () {
    int n; scanf ("%d",&n);
    scanf ("%s",s);
    assert((int)strlen(s) == n);
    int k; scanf ("%d",&k);
    vector<bool> bad(26);
    while (k--) {
        char c; scanf (" %c",&c);
        bad[c-'a'] = true;
    }
    int ed = -1;
    for (int i = 0; i < n; i++) if (bad[s[i]-'a']) ed = i;
    if (!~ed) {
        printf ("0\n");
        return;
    }
    int cnt = 0, mx = 0, cb = 0;
    bool fi = 1;
    for (int i = 0; i <= ed; i++) {
        if (!bad[s[i]-'a']) mx = max(mx,(++cnt) + (!fi));
        else {
            if (!fi) mx = max(mx,1);
            cnt = 0, ++cb, fi = 0;
        }
    }
    printf ("%d\n",mx);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}