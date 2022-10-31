#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, d; cin >> n >> d;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if(arr.back() <= d || arr[0]+arr[1] <= d) cout << "YES" << endl;
    else cout << "NO" << endl;
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