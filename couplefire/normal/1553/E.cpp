#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i], --arr[i];
    vector<int> stuff(n, 0);
    for(int i = 0; i<n; i++){
        int d = arr[i]<=i?i-arr[i]:i-arr[i]+n;
        stuff[d]++;
    }
    vector<int> ans;
    for(int i = 0; i<n; i++){
        if(stuff[i] < n-2*m) continue;
        int cnt = n;
        vector<bool> vis(n, 0);
        for(int j = 0; j<n; j++){
            if(vis[j]) continue;
            --cnt; int v = j;
            while(!vis[v])
                vis[v] = 1, v = arr[(v+i)%n];
        }
        if(cnt<=m) ans.push_back(i);
    }
    cout << ans.size() << ' ';
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}