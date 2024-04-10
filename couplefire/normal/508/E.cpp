#include <bits/stdc++.h>
using namespace std;
#define MAXN 601
bool dp[MAXN][MAXN] = {0};

string getAns(int i, int j){
    if(i == j) return "()";
    for(int a = i; a<j; a++){
        if(dp[i][a] && dp[a+1][j]) return getAns(i, a)+getAns(a+1, j);
    }
    return "("+getAns(i+1, j)+")";
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    pair<int, int> seg[n];
    for(int i = 0; i < n; i++){
        cin >> seg[i].first >> seg[i].second;
    }
    for(int len = 0; len<n; len++){
        for(int i = 0; i+len < n; i++){
            if(len == 0){
                if(seg[i].first == 1) dp[i][i] = 1;
                continue;
            }
            for(int j = 0; j<len; j++){
                if(seg[i].first > 2*j+1 || 2*j+1 > seg[i].second) continue;
                if(dp[i][i+j] && dp[i+j+1][i+len]){
                    dp[i][i+len] = 1;
                    continue;
                }
            }
            if(seg[i].first <= 2*len+1 && seg[i].second >= 2*len+1){
                if(dp[i+1][i+len]) dp[i][i+len] = 1;
            }
        }
    }
    if(!dp[0][n-1]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << getAns(0, n-1) << endl;
}