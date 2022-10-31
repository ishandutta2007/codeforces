#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x; cin >> n;
    vector<int> arr(n), prv(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    cin >> x;
    for(int i = 0; i<n; ++i){
        if(i==0 || arr[i]+arr[i-1]<2*x){
            prv[i] = i-1; continue;
        }
        if(i==1 || arr[i]+arr[i-1]+arr[i-2]<3*x){
            prv[i] = i-2; continue;
        }
        prv[i] = prv[i-1];
    }
    int cur = n-1, ans = 0;
    while(cur>=0){
        ans += cur-prv[cur];
        cur = prv[cur]-1;
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}