#include<bits/stdc++.h>
using namespace std;
const int MN = 1e3+5;
const int INF = 1e9;
void solve () {
    int n, s; scanf ("%d %d",&n,&s);
    vector<int> psa(n+1);
    for (int i = 1; i <= n; i++) {
        int x; scanf ("%d",&x);
        psa[i] = x + psa[i-1];
    }
    int mx = -1;
    for (int L = 1; L <= n; L++) {
        int low = L, high = n, mid, ans = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (psa[mid] - psa[L-1] <= s) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if (psa[ans] - psa[L-1] == s) mx = max(mx,ans - L + 1); 
    }
    if (mx == -1) printf ("-1\n");
    else printf ("%d\n",n-mx);
}
int main () {
    int _t; scanf ("%d",&_t);
    while (_t--) solve();
    return 0;
}