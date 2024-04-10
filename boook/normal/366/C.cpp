#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< LL > VLL;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
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
#define MAX 20000
#define INF 0x3f3f3f3f

int x[MAX] , t[MAX];
int dp[MAX / 10][MAX] , n , m , q;
int main(){
    RII(n , m);
    REPNM(i , 1 , n + 1) RI(x[i]);
    REPNM(i , 1 , n + 1) RI(q) , t[i] = q * m;

    MEM(dp , -INF);

    dp[0][MAX / 2] = 0;
    REPNM(i , 1 , n + 1){
        REPNM(j , 0 , MAX){
            if(j + x[i] - t[i] < 0 || j + x[i] - t[i] >= MAX) continue;
            dp[i][j + x[i] - t[i]] = max(dp[i - 1][j + x[i] - t[i]] , dp[i - 1][j] + x[i]);
        }
    }
    if(!dp[n][MAX / 2]) dp[n][MAX / 2] = -1;
    printf("%d\n", dp[n][MAX / 2]);
    return 0;
}