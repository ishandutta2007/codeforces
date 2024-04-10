#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
void solve () {
    int n; scanf ("%d",&n);
    int x = 0;
    vector<int> v(n);
    for (int &i : v) {
        scanf ("%d",&i);
        x ^= i;
    }
    for (int &i : v) {
        if ((x ^ i) == i) {
            printf ("%d\n",i);
            return;
        }
    }
    assert(false);
}
int main () { 
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}