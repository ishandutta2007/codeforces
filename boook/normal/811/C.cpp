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
#define MAX 5050
#define INF 0x3f3f3f3f
typedef pair<PII , int> PIII;
int n , x[MAX] , use[MAX] , f[MAX] , b[MAX];
int dp[MAX];
vector<PIII> v;
int solve(){
    int res = 0;
    REP(i , v.size()){
        PII lr = v[i].A;
        int val = v[i].B;
        // DB4(lr.A , lr.B , val , "");
        if(i != 0 && v[i].A.B != v[i - 1].A.B){
            REPNM(j , v[i - 1].A.B + 1 , v[i].A.B + 1)
                dp[j] = max(dp[j] , dp[v[i - 1].A.B]);
        }
        dp[lr.B] = max(dp[lr.B] , dp[lr.A - 1] + val);
        res = max(res , dp[lr.B]);
    }
    return res;
}
int32_t main(){
    cin >> n;
    REPNM(i , 1 , n + 1) cin >> x[i];
    REPNM(i , 1 , n + 1) {
        if(use[x[i]] == 0) f[x[i]] = i;
        use[x[i]] = 1;
    }
    RREP(i , n , 1){
        if(use[x[i]] != 2) b[x[i]] = i;
        use[x[i]] = 2;
    }
    MEM(use , -1);
    REPNM(i , 1 , n + 1){
        if(f[x[i]] == b[x[i]]) v.pb(mp(mp(i , i) , x[i]));
        else {
            int now = 0 , lim = i;
            RREP(j , i , 1){
                if(b[x[j]] > i) break;
                if(use[x[j]] != i) use[x[j]] = i , now ^= x[j];
                lim = min(lim , f[x[j]]);
                if(lim == j) v.pb(mp(mp(j , i) , now));
            }
        }
    }
    int ans = solve();
    cout << ans << endl;
    return 0;
}