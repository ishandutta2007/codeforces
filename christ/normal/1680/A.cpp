#include <bits/stdc++.h>
using namespace std;
const int MN = 105;
void solve () {
    int l,r,l2,r2; scanf ("%d %d %d %d",&l,&r,&l2,&r2);
    int mr = min(r,r2), ml = max(l,l2);
    if (ml <= mr) printf ("%d\n",min(l+l2,ml));
    else printf ("%d\n",l + l2);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}