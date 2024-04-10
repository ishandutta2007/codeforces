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
#define MAX 400000
#define INF 0x3f3f3f3f

typedef pair<int , PII> PIII;
int n , m , dp[MAX] , ans;
PIII x[MAX];

int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , m) cin >> x[i].B.A >> x[i].B.B >> x[i].A;
    sort(x , x + m , greater<PIII>());
    VPII sol;
    int tmp = x[0].A;
    REP(i , m){
        PII now = x[i].B;
        sol.pb(mp(now.A , dp[now.B] + 1));
        if(i == m - 1 || tmp != x[i + 1].A){
            for(auto j : sol) dp[j.A] = max(dp[j.A] , j.B) , ans = max(ans , dp[j.A]);
            sol.clear();
            tmp = x[i + 1].A;
        }
    }
    cout << ans << "\n";
    return 0;
}