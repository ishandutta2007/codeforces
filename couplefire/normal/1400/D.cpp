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
        vector<int> temp[n+1];
        int arr[n+1];
        for(int i = 0; i<n; i++){
            cin >> arr[i+1];
            temp[arr[i+1]].push_back(i+1);
        }
        int prev[n+1];
        int next[n+1];
        for(int i = 1; i<=n; i++){
            if(temp[i].empty()) continue;
            prev[temp[i].front()] = 0;
            for(int j = 1; j<temp[i].size(); j++) prev[temp[i][j]] = temp[i][j-1];
            next[temp[i].back()] = n+1;
            for(int j = temp[i].size()-2; j>=0; j--) next[temp[i][j]] = temp[i][j+1];
        }
        int prefix[n+1][n+1];
        for(int i = 1; i<=n; i++){
            prefix[i][0] = 0;
            for(int j = 1; j<=n; j++) prefix[i][j] = prefix[i][j-1]+(arr[j] == i);
        }
        long long dp1[n+1][n+1];
        long long dp2[n+1][n+1];
        for(int siz = 0; siz <= n; siz++){
            for(int i = 1; i+siz <= n; i++){
                int j = i+siz;
                dp1[i][j] = 0;
                dp2[i][j] = 0;
                if(j-i+1 < 4){
                    continue;
                }
                dp1[i][j] = dp1[i+1][j]+dp1[i][j-1]-dp1[i+1][j-1];
                if(arr[i] == arr[j]) continue;
                if(prev[j] > i){
                    dp2[i][j] = dp2[i][prev[j]]+1ll*(prefix[arr[i]][j]-prefix[arr[i]][prev[j]])*(prefix[arr[j]][prev[j]]-prefix[arr[j]][i]);
                }
                else if(next[i] < j){
                    dp2[i][j] = dp2[next[i]][j]+1ll*(prefix[arr[j]][next[i]]-prefix[arr[j]][i])*(prefix[arr[i]][j]-prefix[arr[i]][next[i]-1]);
                }
                dp1[i][j] += dp2[i][j];
            }
        }
        long long ans = dp1[1][n];
        for(int i = 1; i<=n; i++){
            long long sz = temp[i].size();
            ans += sz*(sz-1)*(sz-2)*(sz-3)/24;
        }
        cout << ans << endl;
    }
}