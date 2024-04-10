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
#define INF 0x3f3f3f3f

int n , t;
double p;
double dp[MAX][MAX];
int32_t main(){
    cin >> n >> p >> t;
    dp[0][0] = 1;
    REP(i , 0 , t){
        REP(j , 0 , n + 1){
            if(j == n) dp[i + 1][j] += dp[i][j];
            else {
                dp[i + 1][j + 1] += dp[i][j] * p;
                dp[i + 1][j] += dp[i][j] * (1 - p);
            }
        }
    }
    double ans = 0;
    REP(i , 1 , n + 1){
        ans = ans + dp[t][i] * i;
    }
    printf("%.011f\n", ans);
    return 0;
}