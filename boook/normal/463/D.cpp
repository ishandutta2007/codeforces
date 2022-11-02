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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , k;
int x[MAX] , dp[MAX];
VI v[MAX];
int F(int a , int b){
    REP(i , v[a].size()){
        if(v[b][i] > v[a][i]) return 0;
    }
    return 1;
}
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(times , k){
        REPNM(i , 1 , n + 1) cin >> x[i];
        REPNM(i , 1 , n + 1) v[x[i]].pb(i);
        v[0].pb(0);
    }
    REPNM(i , 1 , n + 1){
        REP(j , i){
            if(F(x[i] , x[j])) dp[i] = max(dp[i] , dp[j] + 1);
        }
    }
    int ans = 0;
    REPNM(i , 1 , n + 1) ans = max(ans , dp[i]);
    cout << ans << "\n"; 
    return 0;
}