#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        for(int i = 0; i<n; i++) cin >> arr[i+1];
        int ans[n+1];
        for(int i = 1; i<=n; i++) ans[i] = INF;
        int curmax = n+1;
        vector<int> occur[n+1];
        for(int i = 1; i <= n; i++) occur[i].push_back(0);
        for(int i = 1; i<= n; i++){
            occur[arr[i]].push_back(i);
        }
        for(int i = 1; i<=n; i++) occur[i].push_back(n+1);
        for(int i = 1; i<=n; i++){
            int maxdif = 0;
            for(int j = 0; j<occur[i].size()-1; j++) maxdif = max(maxdif, occur[i][j+1]-occur[i][j]-1);
            if(maxdif+1 >= curmax) continue;
            for(int j = maxdif+1; j<curmax; j++) ans[j] = i;
            curmax = maxdif+1;
        }
        for(int i = 1; i<=n; i++){
            if(ans[i] == INF) cout << -1 << " ";
            else cout << ans[i] << " ";
        }
        cout << endl;
    }
}