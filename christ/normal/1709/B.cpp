#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7, MM = 1e5;
int main () {
    int n,m; scanf ("%d %d",&n,&m);
    vector<int> a(n+1);
    vector<long long> psa(n+1), rpsa(n+1);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        psa[i] = psa[i-1];
        if (i > 1) psa[i] += max(0, a[i-1] - a[i]);
    }
    for (int i = n-1; i >= 1; i--) {
        rpsa[i] = rpsa[i+1] + max(0,a[i+1] - a[i]);
    }
    while (m--) {
        int l,r; scanf ("%d %d",&l,&r);
        if (r >= l) {
            printf ("%lld\n",psa[r] - psa[l]);
        } else {
            printf ("%lld\n",rpsa[r] - rpsa[l]);
        }
    }
    return 0;
}