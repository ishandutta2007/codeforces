#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 2020
#define INF 100000000000LL

int n , h;
double p;
int x[MAX];
double dp[MAX][MAX][2][2];
double tma , tmb;
double DP(int l , int r , int fr ,int ba){
    // DB4(l , r , fr , ba);
    if(dp[l][r][fr][ba] >= 0) return dp[l][r][fr][ba];
    if(l > r) return dp[l][r][fr][ba] = 0;
    int ll = (fr == 0) ? x[l - 1] : min(x[l] , x[l - 1] + h);
    int rr = (ba == 1) ? x[r + 1] : max(x[r] , x[r + 1] - h);
    if(fr == 1 && x[l - 1] + h > x[l] && l == r)
        return dp[l][r][fr][ba] = DP(l + 1 , r , fr , ba) + min(rr - x[l] , h);
    if(ba == 0 && x[r + 1] - h < x[r] && l == r)
        return dp[l][r][fr][ba] = DP(l , r - 1 , fr , ba) + min(x[r] - ll , h);


    if(fr == 1 && x[l - 1] + h > x[l])
        return dp[l][r][fr][ba] = DP(l + 1 , r , fr , ba) + min(x[l + 1] - x[l] , h);
    if(ba == 0 && x[r + 1] - h < x[r])
        return dp[l][r][fr][ba] = DP(l , r - 1 , fr , ba) + min(x[r] - x[r - 1] , h);
    dp[l][r][fr][ba] = 0;
    dp[l][r][fr][ba] += (DP(l + 1 , r , 0 , ba) + min(x[l] - ll , h)) * tma;
    if(l == r) dp[l][r][fr][ba] += (DP(l + 1 , r , 1 , ba) + min(rr - x[l] , h)) * tmb;
    else dp[l][r][fr][ba] += (DP(l + 1 , r , 1 , ba) + min(x[l + 1] - x[l] , h)) * tmb;
    if(l == r) dp[l][r][fr][ba] += (DP(l , r - 1 , fr , 0) + min(x[r] - ll , h)) * tma;
    else dp[l][r][fr][ba] += (DP(l , r - 1 , fr , 0) + min(x[r] - x[r - 1] , h)) * tma;
    dp[l][r][fr][ba] += (DP(l , r - 1 , fr , 1) + min(rr - x[r] , h)) * tmb;
    return dp[l][r][fr][ba];
}
int32_t main(){
    IOS;
    cin >> n >> h >> p;
    tma = p / 2.0 , tmb = (1.00 - p) / 2.0;
    x[0] = -INF , x[n + 1] = INF;
    REP(i , 1 , n + 1) cin >> x[i];
    sort(x + 1 , x + 1 + n);
    REP(i , 0 , MAX) REP(j , 0 , MAX)
        REP(k , 0 , 2) REP(l , 0 , 2) dp[i][j][k][l] = -1;
    double ans = DP(1 , n , 0 , 1);
    printf("%.011f\n", ans);
    return 0;
}