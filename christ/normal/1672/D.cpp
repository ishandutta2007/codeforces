#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
int a[MN], b[MN];
void solve () {
    int n; scanf ("%d",&n);
    for (int i = 1; i <= n; i++) scanf ("%d",a+i);
    for (int i = 1; i <= n; i++) scanf ("%d",b+i);
    vector<int> at(n+1);
    vector<set<int>> idxOf(n+1);
    for (int i = 1; i <= n; i++) {
        idxOf[a[i]].insert(i); at[i] = 1;
    }
    int pp = 1;
    for (int i = 1; i <= n; i++) {
        while (at[pp] == 0) ++pp;
        int cur = a[pp];
        at[pp]--;
        if (cur != b[i]) {
            auto it = idxOf[cur].upper_bound(pp);
            if (it == idxOf[cur].end()) {
                printf ("NO\n");
                return;
            }
            ++at[*it];
            --i;
        }
    }
    printf ("YeS\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}