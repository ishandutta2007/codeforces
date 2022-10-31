#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int dp[82][82][3321];
int n;
int arr[82];
vector<int> pos = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        if(arr[i] == 1) pos.push_back(i);
    }
    for(int i = 0; i<=pos.size()-1; i++) for(int j = 0; j<=n; j++) for(int k = 0, e = n*(n-1)/2; k<=e; k++) dp[i][j][k] = INF;
    for(int k = 0; k<=n*(n-1)/2; k++) dp[0][0][k] = 0;
    for(int i = 1; i<=pos.size()-1; i++){
        for(int j = 0; j<=n; j++){
            if(i > j) continue;
            for(int k = 0, e = n*(n-1)/2; k<=e; k++){
                int t = abs(j-pos[i]);
                if(t > k) continue;
                for(int a = 0; a<=j-1; a++){
                    if(dp[i-1][a][k-t] == INF) continue;
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][a][k-t]+(j-a-1)*(j-a-2)/2);
                }
            }
        }
    }
    // cout << dp[2][4][1] << endl;
    for(int k = 0; k<=n*(n-1)/2; k++){
        int ans = INF;
        for(int j = 0; j<=n; j++) ans = min(ans, dp[pos.size()-1][j][k]+(n-j)*(n-j-1)/2);
        cout << (n-pos.size()+1)*(n-pos.size())/2-ans << " ";
    }
}