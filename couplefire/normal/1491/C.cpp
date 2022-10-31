#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    vector<int> cur;
    cur.assign(n+1, 0);
    long long ans = 0;
    for(int i = 0; i<n; i++){
        ans += max(arr[i]-cur[i]-1, 0);
        for(int j = min(n-1, i+arr[i]); j>i+1; j--) cur[j]++;
        cur[i+1] += max(0, cur[i]-arr[i]+1);
    }
    cout << ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}