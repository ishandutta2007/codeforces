#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , x[MAX] , dp[MAX][30] , sum[MAX];

string s;
int gi[MAX] , ni[MAX];
int C(int a , int b){
    if(a < b) return 0;
    else return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
void getcountmath(){
    gi[0] = gi[1] = ni[0] = ni[1] = 1;
    REP(i , 2 , MAX) gi[i] = gi[i - 1] * i % mod;
    REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    REP(i , 1 , MAX) ni[i] = ni[i - 1] * ni[i] % mod;
}
int32_t main(){
    IOS;
    getcountmath();
    cin >> n >> s;
    REP(i , 0 , s.size()) x[i + 1] = s[i] - 'a';

    REP(i , 1 , n + 1){
        RREP(j , n , 2){
            int cnt = (sum[j - 1] - dp[j - 1][x[i]] + mod) % mod;
            sum[j] = (sum[j] + cnt - dp[j][x[i]] + mod) % mod;
            dp[j][x[i]] = cnt;
        }
        if(dp[1][x[i]] == 0) sum[1] ++;
        dp[1][x[i]] = 1;
    }
    int ans = 0;
    REP(i , 1 , n + 1){
        REP(j , 0 , 30){
            if(dp[i][j]){
                ans = (ans + C(n - 1 , i - 1) * dp[i][j]) % mod;
                // DB4(i , j , dp[i][j] , "");
            }
        }
    }
    cout << ans << endl;
    return 0;
}