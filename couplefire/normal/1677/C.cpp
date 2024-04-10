#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    vector<int> arr(n), brr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i], --arr[i];
    for(int i = 0; i<n; ++i)
        cin >> brr[i], --brr[i];
    vector<int> permu(n);
    for(int i = 0; i<n; ++i)
        permu[arr[i]] = brr[i];
    vector<bool> vis(n, 0);
    int bruh = 0;
    for(int v = 0; v<n; ++v){
        if(vis[v]) continue;
        int u = v, cnt = 0;
        while(!vis[u])
            vis[u] = 1, u = permu[u], ++cnt;
        bruh += cnt/2;
    }
    cout << 2ll*bruh*(n-bruh) << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}