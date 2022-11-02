/*input
5 3
11 1
22 2
16 1
73 3
35 3
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 6000
#define INF 0x3f3f3f3f

int n , m , t[MAX];
double dp[MAX][2] , nt[MAX][2] , p[MAX] , v[MAX];
double ppow(double a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a , k >> 1);
    if(k % 2 == 1) return ppow(a * a , k >> 1) * a; 
}
int32_t main(){
	scanf("%d%d" , &n , &m);
    int sum = 0;
    REP(i , 1 , n + 1) scanf("%lf%d" , &p[i] , &t[i]) , p[i] /= 100 , sum += t[i];
    REP(i , 1 , n + 1) v[i] = ppow(1 - p[i] , t[i]);
    if(sum <= m) return printf("%d\n", n) , 0;
    
    double ans = 0 , all = 0;
    nt[1][1] = 1;
    REP(j , 1 , n + 1) {
        REP(ii , 0 , m + 2) dp[ii][0] = nt[ii][0];
        REP(ii , 0 , m + 2) dp[ii][1] = nt[ii][1];
        MEM(nt , 0);
        double tmp = 0;
        REP(i , 1 , m + 2){
             dp[i][0] += dp[i][1] + tmp;
             if(i + t[j] <= m + 10){
                 nt[i + t[j]][1] += dp[i][1] * v[j];
                 dp[i + t[j]][0] -= dp[i][1] * v[j];
             }
             tmp = dp[i][0] * (1.0 - p[j]);
             if(tmp < 1e-20) tmp = 0;
        //      dp[i + 1][0] += tmp;
             nt[i + 1][1] += dp[i][0] * p[j];
        }
        if(j >= 2) ans += (j - 1) * dp[m + 1][0] , all += dp[m + 1][0];
    }
    ans += n * (1 - all);
    printf("%.11f\n", ans);
    return 0;
}