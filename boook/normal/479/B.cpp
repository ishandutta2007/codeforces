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
#define MAX 100000
#define INF 0x3f3f3f3f


int n , m , x[MAX];
VPII ans;
int32_t main(){
    cin >> n >> m;
    REP(i , n) cin >> x[i];
    PII big , sml;
    REP(i , m){
        big = mp(x[0] , 0) , sml = mp(x[0] , 0);
        REP(j , n){
            big = max(big , mp(x[j] , j)) , sml = min(sml , mp(x[j] , j));
        }
        if(big.A - sml.A <= 1) break;
        else ans.pb(mp(big.B , sml.B)) , x[big.B] -- , x[sml.B] ++;
    }
    big = mp(x[0] , 0) , sml = mp(x[0] , 0);
    REP(j , n) big = max(big , mp(x[j] , j)) , sml = min(sml , mp(x[j] , j));

    cout << big.A - sml.A << " " << ans.size() << endl;
    REP(i , ans.size()) cout << ans[i].A + 1 << " " << ans[i].B + 1 << endl;
    return 0;
}