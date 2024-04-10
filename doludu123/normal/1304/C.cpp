#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
#define MAXN 200000

void solve () {
    int n,m;
    cin >> n >> m;
    int t,l,r,pt=0,pl=m,pr=m;
    bool is = true;
    fop (i,0,n) {
        cin >> t >> l >> r;
        int k = t - pt;
        int nl = pl - k, nr = pr + k;
        if (nl < l) {
            if (r - nl > r - l + nr - nl) is = false;
        } else {
            if (nr - l > nr - nl + r - l) is = false;
        }
        pt = t;
        pl = max(nl, l);
        pr = min(nr, r);
    }
    if (is) cout << "YES" << endl;
    else cout << "NO" << endl;
} 

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}