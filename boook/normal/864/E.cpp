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
#define MAX 110
#define INF 0x3f3f3f3f

int dp[110][2020] , pa[110][2020];
int n , t[MAX] , d[MAX] , p[MAX];
int sol[MAX];
int cmp(int a , int b){
    return d[a] < d[b];
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> t[i] >> d[i] >> p[i];
    REP(i , 1 , n + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + n , cmp);
    REP(i , 1 , n + 1){
        int id = sol[i];
        REP(j , 0 , 2020){
            dp[i][j] = dp[i - 1][j];
            pa[i][j] = j;
            if(j < d[id] && j - t[id] >= 0){
                if(dp[i][j] <= dp[i - 1][j - t[id]] + p[id]){
                    dp[i][j] = dp[i - 1][j - t[id]] + p[id];
                    pa[i][j] = j - t[id];
                }
            }
        }
    }
    int big = 0;
    REP(i , 0 , 2020) if(dp[n][i] > dp[n][big]) big = i;
    int num = 0 , now = big;
    stack<int> cc;
    RREP(i , n , 1){
        if(pa[i][now] != now) num ++ , cc.push(sol[i]);
        now = pa[i][now];
    }
    cout << dp[n][big] << endl;
    cout << num << endl;
    while(cc.size()) cout << cc.top() << " " , cc.pop(); cout << endl;
    return 0;
}