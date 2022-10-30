#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    map<int, int> mp;
    int n, m; cin >> n >> m;
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        mp[min(u, v)]++;
    }
    int q; cin >> q;
    while(q--){
        int _; cin >> _;
        if(_ == 1){
            int u, v; cin >> u >> v;
            mp[min(u, v)]++;
        } else if(_ == 2){
            int u, v; cin >> u >> v;
            mp[min(u, v)]--;
            if(mp[min(u, v)]==0) mp.erase(min(u, v));
        } else cout << n-mp.size() << '\n';
    }
}