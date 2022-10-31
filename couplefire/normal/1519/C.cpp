#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> arr(n);
        vector<int> _u(n), _s(n);
        for(int i = 0; i<n; i++) cin >> _u[i], --_u[i];
        for(int i = 0; i<n; i++) cin >> _s[i];
        for(int i = 0; i<n; i++) arr[_u[i]].push_back(_s[i]);
        for(int i = 0; i<n; i++) sort(arr[i].begin(), arr[i].end());
        for(int i = 0; i<n; i++) reverse(arr[i].begin(), arr[i].end());
        for(int i = 0; i<n; i++){
            for(int j = 1; j<arr[i].size(); j++) arr[i][j] += arr[i][j-1];
        }
        sort(arr.begin(), arr.end(), [&](const vector<int> &a, const vector<int> &b){
            return a.size() > b.size();
        });
        for(int k = 1; k<=n; k++){
            int ans = 0;
            for(int i = 0; i<n; i++){
                if(arr[i].size() < k) break;
                ans += arr[i][arr[i].size()/k*k-1];
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}