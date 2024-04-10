#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7, MM = 1e5;
void solve () {
    vector<int> a(4);
    int ours; scanf ("%d",&ours);
    scanf ("%d %d %d",&a[1],&a[2],&a[3]);
    printf (a[ours] > 0 && a[a[ours]] > 0 ? "YES\n" : "NO\n");
    
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}