#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> stuff;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[j][i];
            stuff.push_back({arr[j][i], j});
        }
    }
    sort(stuff.begin(), stuff.end());
    reverse(stuff.begin(), stuff.end());
    set<int> tmpst;
    for(int i = 0; i<stuff.size() && tmpst.size() < min(m, n); i++){
        tmpst.insert(stuff[i].second);
    }
    int cnt = tmpst.size();
    vector<int> col; col.push_back(-1);
    for(auto x : tmpst) col.push_back(x);
    int dp[1<<n][cnt+1];
    int best[1<<n][cnt+1];
    memset(dp, 0, sizeof dp);
    memset(best, 0, sizeof best);
    for(int i = 1; i<=cnt; i++){
        for(int num = 0; num<n; num++){
            for(int mask = 0; mask<(1<<n); mask++){
                int tmp = 0;
                for(int bit = 0; bit<n; bit++){
                    if(mask&(1<<bit)) tmp += arr[col[i]][bit];
                }
                best[mask][i] = max(best[mask][i], tmp);
            }
            rotate(arr[col[i]].begin(), arr[col[i]].begin()+1, arr[col[i]].end());
        }
    }
    // cout << best[0][2] << endl;
    for(int i = 1; i<=cnt; i++){
        for(int mask = 0; mask < (1<<n); mask++){
            for(int sub = mask;; sub = (sub-1)&mask){
                dp[mask][i] = max(dp[mask][i], dp[mask^sub][i-1]+best[sub][i]);
                if(sub == 0) break;
            }
        }
    }
    cout << dp[(1<<n)-1][cnt] << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}