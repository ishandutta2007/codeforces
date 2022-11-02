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
#define MAX 109
#define INF 0x3f3f3f3f

int n , ans;
int dp[MAX][3][MAX][2];
void F(int floor , int ty , int sum , int pp){
    // if(floor == 3 || floor == 5)DB4(floor , ty , sum , "");
    // if(floor > 5) return ;

    if(sum == n) { ans = min(ans , floor); return; }
    if(sum > n) return ;

    if(dp[floor][ty][sum][pp] != -1) return ;
    dp[floor][ty][sum][pp] = 0;

    if(ty != 0){
        int lim = floor / 2 + 1 , tma = sum;
        while(tma + 4 <= n && lim > 0){
            tma += 4 , lim --;
            F(floor + 2 , 0 , tma , 0);
        }
    }
    if(ty != 1){

        int lim = floor / 2 + 1 , tmb = sum;
        // DBGG("53" , lim);
        F(floor + 2 , 1 , sum + 2 , 0);
        while(tmb + 4 <= n && lim > 0){
            tmb += 4 , lim --;
            F(floor + 2 , 1 , tmb - 2 , 0);
            F(floor + 2 , 1 , tmb , 0);
            if(tmb + 2 <= n && lim > 0) F(floor + 2 , 1 , tmb + 2 , 0);
            // DBGG("60 ", tmb);
        }
    }
    if(pp == 0) F(floor + 2 , 2 , sum , 1);
}
int32_t main(){
    MEM(dp , -1);
    // F(3 , 0 , 5 , 0);
    // REP(i , 100){
        // n = i + 1;
    cin >> n;
        ans = INF;
        F(1 , 0 , 0 , 0);
        F(1 , 1 , 1 , 0);
        F(1 , 2 , 0 , 0);
        // DBGG(n , ans);
        cout << ans << "\n";
    // }cout << endl;
    return 0;
}