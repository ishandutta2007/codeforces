#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    int cnt[n+1];
    fill(cnt, cnt+n+1, 0);
    for(int i = 0; i<n; i++){
        cnt[arr[i]]++;
    }
    int mcnt = 0;
    for(int i = 0; i<=n; i++) mcnt = max(mcnt, cnt[i]);
    if(mcnt*2-1 > n){
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> chains;
    for(int i = 0; i<n; i++){
        int cur = i;
        while(i < n-1 && arr[i] != arr[i+1]) i++;
        chains.push_back({arr[cur], arr[i]});
        // cout << cur << " " << i << endl;
    }
    int tot = chains.size();
    int num[n+1];
    int contain[n+1];
    fill(num, num+n+1, 0);
    fill(contain, contain+n+1, 0);
    for(auto x : chains){
        if(x.first == x.second){
            num[x.first]++;
            contain[x.first]++;
        }
        else contain[x.first]++, contain[x.second]++;
    }
    int ans = tot-1;
    for(int i = 0; i<=n; i++){
        if(num[i]-1 > tot-contain[i]){
            ans += num[i]-1-tot+contain[i];
        }
    }
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}