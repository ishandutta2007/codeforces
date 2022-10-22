#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
void solve () {
    int n; scanf ("%d",&n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf ("%d",&a[i]);
    long long sum = 0;
    int m; scanf ("%d",&m);
    while (m--) {
        int x; scanf ("%d",&x);
        sum += x;
    }
    printf ("%d\n",a[(int)(sum%n)]);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}