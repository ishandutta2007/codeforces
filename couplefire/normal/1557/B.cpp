#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> mp;
    vector<int> arr(n);
    vector<int> og;
    for(int i = 0; i<n; ++i)
        cin >> arr[i], mp[arr[i]] = i;
    og = arr;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<n;){
        int id = mp[arr[i]];
        while(i<n && id<n && arr[i]==og[id])
            ++i, ++id;
        --k;
    }
    cout << (k>=0?"YES":"NO") << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}