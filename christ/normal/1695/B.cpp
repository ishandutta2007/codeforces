#include<bits/stdc++.h>
using namespace std;
const int MN = 40+5;
void solve () {
    int n; scanf ("%d",&n);
    vector<int> a(n);
    for (auto &x : a) scanf ("%d",&x);
    if (n % 2 == 1) {
        printf ("Mike\n");
        return;
    }
    long long t1 = LLONG_MAX, t2 = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (i&1) {
            t2 = min(t2,(long long)a[i] * n + i);
        } else {
            t1 = min(t1,(long long)a[i] * n + i);
        }
    }
    if (t1 > t2) printf ("Mike\n");
    else printf ("Joe\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}