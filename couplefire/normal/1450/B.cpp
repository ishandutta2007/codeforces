#include <bits/stdc++.h>
using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i = 0; i<n; i++){
        bool tmp = true;
        for(int j = 0; j<n; j++){
            if(dist(arr[i], arr[j]) > k){
                tmp = false;
                break;
            }
        }
        if(tmp){
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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