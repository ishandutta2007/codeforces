#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
void solve () {
    int n,z; scanf ("%d %d",&n,&z);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf ("%d",&x);
        ret = max(ret,x|z);
    }  
    printf ("%d\n",ret);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}