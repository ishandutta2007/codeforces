#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
void solve () {
    int n; scanf ("%d",&n);
    vector<long long> v(n);
    for (long long &i : v) scanf ("%lld",&i);
    for (int i = 0; i+1 < n; i++) {
        long long take = v[i];
        if (take < 0) {
            printf ("No\n");
            return;
        }
        if (take == 0) {
            break;
        }
        v[i] -= take;
        v[i+1] += take;
    }
    for (int i = 0; i < n; i++) if (v[i] != 0) {
        printf ("No\n");
        return;
    }
    printf ("Yes\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}