#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define pb push_back
#define int long long
#define MAX 2020
#define mod 998244353LL

int n , m , k , dp[MAX][MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    dp[1][0] = m;
    REP(i , 2 , n + 1){
        REP(j , 0 , k + 1){
            dp[i][j] = (dp[i - 1][j]);
            if(j != 0){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (m - 1)) % mod;
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}