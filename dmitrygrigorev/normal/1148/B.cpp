#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, ta, tb;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n), b(m);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n;i++) a[i] += ta;
    for (int i=0; i < m; i++) cin >> b[i];
    int ans = 0;
    if (k >= n){
        cout << -1;
        return 0;
    }
    for (int i=0; i < n; i++){
        if (i > k) continue;
        int L = 0, R = m+1;
        while (R-L>1){
            int M = (L+R)/2;
            if (b[M-1] >= a[i]) R = M;
            else L = M;
        }
        int rem = m-L;
        if (rem+i <= k){
            cout << -1;
            return 0;
        }
        int can = k - i;
        int pos = b[can+L]+tb;
        if (pos > ans) ans=pos;
    }
    cout << ans;
}