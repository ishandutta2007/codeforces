#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    if(n == 2){
        for(auto x : arr) cout << x << " ";
        cout << '\n';
        return;
    }
    int mians = 1e9;
    for(int i = 0; i<n-1; i++)
        mians = min(mians, arr[i+1]-arr[i]);
    int bid = -1, bans = -1;
    for(int i = 1; i<n-2; i++){
        if(arr[i+1]-arr[i] != mians) continue;
        int val = n-2+(arr[n-1]>=arr[0]);
        if(val > bans) bid = i, bans = val;
    }
    if(arr[1]-arr[0] == mians){
        int val = n-2+(arr[1]>=arr[n-1]);
        if(val > bans) bid = 0, bans = val;
    }
    if(arr[n-1]-arr[n-2] == mians){
        int val = n-2+(arr[0] >= arr[n-2]);
        if(val > bans) bid = n-2, bans = val;
    }
    cout << arr[bid] << " ";
    for(int i = bid+2; i<n; i++)
        cout << arr[i] << " ";
    for(int i = 0; i<bid; i++)
        cout << arr[i] << " ";
    cout << arr[bid+1] << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}