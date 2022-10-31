#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    auto eval = [&](int ind){
        if(ind < 0 || ind >= n) return 0;
        int prv = arr[max(ind-1, 0)];
        int nxt = arr[min(ind+1, n-1)];
        int cur = arr[ind];
        if((cur < prv && cur < nxt) || (cur > prv && cur > nxt)) return 1;
        return 0;
    };
    int tot = 0;
    for(int i = 0; i<n; i++) tot += eval(i);
    int ans = tot;
    for(int i = 0; i<n; i++){
        int tmp = tot-eval(i)-eval(i-1)-eval(i+1);
        int p = arr[i];
        if(i > 0) arr[i] = arr[i-1], ans = min(ans, tmp+eval(i)+eval(i-1)+eval(i+1));
        if(i < n-1) arr[i] = arr[i+1], ans = min(ans, tmp+eval(i)+eval(i-1)+eval(i+1));
        arr[i] = p;
    }
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}