#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
vector<int> query (int l, int r) {
    printf ("? %d %d\n",l,r);
    fflush(stdout);
    vector<int> ret(r-l+1);
    for (int &i : ret) scanf ("%d",&i);
    return ret;
}
void solve () {
    int n; scanf ("%d",&n);
    int low = 1, high = n/2, mid, ans = n/2+1;
    while (low <= high) {
        mid = (low + high) / 2;
        vector<int> got = query(1,2*mid);
        int cnt = 0;
        for (int i : got) cnt += i > 2 * mid;
        if (cnt&1) high = (ans = mid) - 1;
        else low = mid + 1;
    }
    if (query(ans * 2 - 1, ans * 2 - 1)[0] == ans * 2 - 1) printf ("! %d\n",ans * 2 - 1);
    else printf ("! %d\n",ans * 2);
    fflush(stdout);
}
int main () { 
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}