#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
void solve () {
    int n; scanf ("%d",&n);
    vector<int> cnt(2);
    for (int i = 1; i <= n; i++) {
        int x; scanf ("%d",&x);
        cnt[x%2]++;
    }
    printf ("%d\n",min(cnt[0],cnt[1]));
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}