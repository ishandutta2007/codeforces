#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<multiset<int>> mst(n);
    vector<pair<int, int>> arr;
    vector<vector<int>> ans(n, vector<int>(m, -1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int a; cin >> a;
            arr.push_back({a, i});
            mst[i].insert(a);
        }
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i<m; i++){
        ans[arr[i].second][i] = arr[i].first;
        mst[arr[i].second].erase(mst[arr[i].second].lower_bound(arr[i].first));
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(ans[i][j] != -1){
                cout << ans[i][j] << " ";
            }
            else{
                cout << (*mst[i].begin()) << " ";
                mst[i].erase(mst[i].begin());
            }
        }
        cout << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}