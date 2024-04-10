#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int n;
vector<int> arr; //1:r, 0:l

int cost(int i, int j){
    if(j-i == 1){
        return (arr[i]^1)+(arr[i+1]^0);
    }
    if(j-i == 2){
        return min((arr[i]^1)+(arr[i+1]^1)+(arr[i+2]^0), (arr[i]^1)+(arr[i+1]^0)+(arr[i+2]^0));
    }
    return (arr[i]^1)+(arr[i+1]^1)+(arr[i+2]^0)+(arr[i+3]^0);
}

void shift(){
    vector<int> temp = arr;
    for(int i = 1; i<n; i++){
        arr[i] = temp[i+1];
    }
    arr[n] = temp[1];
}

int solve(){
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        dp[i] = INF;
        for(int j = 1; j<=3; j++){
            if(i-j <= 0) continue;
            dp[i] = min(dp[i], dp[i-j-1]+cost(i-j, i));
        }
    }
    return dp[n];
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        arr.clear();
        arr.resize(n+1);
        string s; cin >> s;
        for(int i = 0; i<n; i++){
            char c = s[i];
            if(c=='R') arr[i+1] = 1;
            else arr[i+1] = 0;
        }
        int ans = INF;
        ans = min(ans, solve());
        shift();
        ans = min(ans, solve());
        shift();
        ans = min(ans, solve());
        shift();
        ans = min(ans, solve());
        shift();
        ans = min(ans, solve());
        shift();
        ans = min(ans, solve());
        shift();
        cout << ans << endl;
    }
}