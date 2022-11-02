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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , x[MAX];
double dp[110][MAX * 100] , pre[MAX * 100];
double query(int now){
    if(now >= 0) return pre[now];
    else return 0;
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    if(m == 1){
        cout << 1 << endl;
        return 0;
    }
    dp[0][0] = m - 1;
    REP(i , 1 , n + 1){
        pre[0] = dp[i - 1][0];
        REP(j , 1 , n * m + 1)
            pre[j] = pre[j - 1] + dp[i - 1][j];
        REP(j , 1 , n * m + 1){
            double tmp = query(j - 1) - query(j - m - 1);
            if(j - x[i] >= 0) tmp -= dp[i - 1][j - x[i]];
            dp[i][j] = tmp / ((double)(m - 1));
            // DB4(i , j , dp[i][j] , query(j - 1));
        }
    }

    int sum = 0;
    REP(i , 1 , n + 1) sum += x[i];
    double ans = 1;
    REP(i , 1 , sum) ans += dp[n][i];
    printf("%.015f\n", ans);
    return 0;
}