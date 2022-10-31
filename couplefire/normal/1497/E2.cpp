#include <bits/stdc++.h>
using namespace std;
#define MAXA 10000006

int num[MAXA];

void solve(){
    int n, k; cin >> n >> k;
    vector<array<int, 2>> stuff(k+1, {1, 0}); //end, val
    vector<int> arr(n+1);
    map<int, vector<int>> mp;
    for(int i = 1; i<=n; i++){
        int a; cin >> a;
        arr[i] = num[a];
        mp[num[a]].push_back(i);
    }
    vector<int> prv(n+1, 0);
    vector<int> nxt(n+1, n+1);
    for(auto &x : mp){
        for(int i = 0; i<x.second.size()-1; ++i) nxt[x.second[i]] = x.second[i+1];
        for(int i = 1; i<x.second.size(); ++i) prv[x.second[i]] = x.second[i-1];
    }
    int dp[n+1][k+1];
    for(int i = 0; i<=k; i++) dp[0][i] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=k; j++){
            if(prv[i] >= stuff[j][0]) stuff[j][1]++;
            while(stuff[j][1] > j){
                if(nxt[stuff[j][0]] <= i) stuff[j][1]--;
                stuff[j][0]++;
            } 
        }
        for(int j = 0; j<=k; j++){
            dp[i][j] = n+1;
            for(int a = 0; a<=j; a++){
                dp[i][j] = min(dp[i][j], dp[stuff[a][0]-1][j-a]+1);
            }
        }
    }
    cout << dp[n][k] << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i<MAXA; ++i) num[i] = i;
    for(int i = 1; i<MAXA; ++i){
        if(num[i] == i){
            for(int j = 1; j*j*i < MAXA; ++j) num[j*j*i] = i;
        }
    }
    // for(int i = 1; i<=25; i++) cout << num[i] << endl;
    int t; cin >> t;
    while(t--) solve();
}