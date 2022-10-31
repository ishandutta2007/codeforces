#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    for(int i = 0; i<n; ++i)
        if(count(arr.begin(), arr.end(), arr[i])&1)
            {cout << -1 << '\n'; return;}
    vector<pair<int, int>> stuff;
    vector<int> ans;
    for(int i = 0; i<(int)arr.size();){
        int j = i+1;
        while(j<(int)arr.size()){
            if(arr[j]==arr[i])
                break;
            ++j;
        }
        for(int k = 1; k<j-i; ++k){
            stuff.push_back({j+k, arr[i+k]});
            arr.insert(arr.begin()+j+k, arr[i+k]);
            arr.insert(arr.begin()+j+k, arr[i+k]);
        }
        ans.push_back((j-i)*2);
        i = 2*j-i;
    }
    cout << stuff.size() << '\n';
    for(auto [a, b] : stuff)
        cout << a << ' ' << b << '\n';
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}