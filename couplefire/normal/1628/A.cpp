#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    vector<int> mex(n);
    vector<bool> occ(n+2, 0);
    int cur = 0;
    for(int i = n-1; i>=0; --i){
        occ[arr[i]] = 1;
        while(occ[cur]) ++cur;
        mex[i] = cur;
    }
    vector<int> brr;
    occ.assign(n+2, 0);
    cur = 0;
    for(int i = 0; i<n;){
        int val = mex[i];
        int tmp = i;
        while(cur<val){
            occ[arr[i]] = 1;
            while(occ[cur]) ++cur;
            ++i;
        }
        brr.push_back(cur);
        for(int j = tmp; j<i; ++j)
            occ[arr[j]] = 0;
        cur = 0;
        if(i==tmp) ++i;
    }
    cout << brr.size() << '\n';
    for(auto x : brr)
        cout << x << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}