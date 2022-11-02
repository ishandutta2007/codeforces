#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 200
#define INF 0x3f3f3f3f

int n , m , ans = 0 , l[MAX] , r[MAX];
int dp[MAX][3];
string p[MAX];
int32_t main(){
    MEM(l , INF) , MEM(r , -1);
    cin >> n >> m;
    REP(i , n) cin >> p[i];
    REP(i , n) REP(j , m + 2){
        if(p[i][j] == '1'){
            l[i] = min(l[i] , j);
            r[i] = max(r[i] , j);
        }
    }
    MEM(dp , INF);
    if(r[n - 1] == -1)
        dp[n - 1][0] = 0 , dp[n - 1][1] = m + 1 , dp[n - 1][2] = 0;
    else 
        dp[n - 1][0] = r[n - 1] * 2 , dp[n - 1][1] = m + 1 , dp[n - 1][2] = r[n - 1];
    // DB4(dp[n - 1][0] , dp[n - 1][1] , dp[n - 1][2] , "");
    int qqq = n - 1;
    RREP(i , n - 2 , 0){
        if(l[i] == INF){ REP(j , 3) dp[i][j] = dp[i + 1][j] + 1; }
        else {
            qqq = i;
            dp[i][0] = min(dp[i + 1][1] + m + 2 , dp[i + 1][0] + r[i] * 2 + 1);
            dp[i][1] = min(dp[i + 1][0] + m + 2 , dp[i + 1][1] + (m + 2 - l[i]) * 2 - 1);
            dp[i][2] = min(dp[i + 1][0] + r[i] + 1 , dp[i + 1][1] + (m + 2 - l[i]));
        }
    }
    cout << min(dp[qqq][0] , min(dp[qqq][1] , dp[qqq][2])) << "\n";
    return 0;
}