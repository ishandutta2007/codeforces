#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    multiset<int> mst;
    int prv = 0;
    for(int i = 0; i<n; i++){
        int b = arr[i];
        auto it1 = mst.upper_bound(prv);
        auto it2 = mst.upper_bound(b);
        if(it1 != mst.end() && (*it1)<b){
            cout << "NO" << '\n';
            return;
        }
        if(it2 != mst.end() && (*it2)<prv){
            cout << "NO" << '\n';
            return;
        }
        mst.insert(b); prv = b;
    }
    cout << "YES" << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}