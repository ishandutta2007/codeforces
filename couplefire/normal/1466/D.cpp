#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long w[n];
        long long sum = 0;
        for(int i = 0; i<n; i++) cin >> w[i], sum += w[i];
        vector<bool> visited(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i<n-1; i++){
            int a, b; cin >> a >> b; --a; --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<pair<long long, int>> arr;
        for(int i = 0; i<n; i++) arr.push_back({w[i], i});
        sort(arr.begin(), arr.end()); reverse(arr.begin(), arr.end());
        cout << sum << " ";
        for(int i = 0; i<n; i++){
            for(int j = 0; j<adj[arr[i].second].size()-1; j++) sum += arr[i].first, cout << sum << " ";
        }
        cout << endl;
    }
}