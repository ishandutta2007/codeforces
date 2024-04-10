#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, u, v; cin >> n >> u >> v;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    int mxdif = 0;
    for(int i = 0; i<n-1; i++) mxdif = max(mxdif, abs(arr[i]-arr[i+1]));
    if(mxdif >= 2){
        cout << 0 << endl;
        return;
    }
    if(mxdif == 1){
        cout << min(u, v) << endl;
        return;
    }
    cout << min(u+v, v+v) << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}