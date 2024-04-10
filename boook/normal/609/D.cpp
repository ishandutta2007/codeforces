/*input
1 2 2 1000000
96
262
1 699
2 699
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , k , money;
int a[MAX] , b[MAX] , x[MAX][2];
vector<PII> v;
int judge(int now){
    int tma = 1 , tmb = 1;
    REP(i , 1 , now + 1) if(a[i] < a[tma]) tma = i;
    REP(i , 1 , now + 1) if(b[i] < b[tmb]) tmb = i;
    vector<PII> sol;
    REP(i , 1 , m + 1){
        if(x[i][0] == 1) sol.pb(mp(a[tma] * x[i][1] , i));
        if(x[i][0] == 2) sol.pb(mp(b[tmb] * x[i][1] , i));
    }
    // DB4("tma = " , tma , "tmb = " , tmb);
    sort(ALL(sol));
    int sum = 0;
    if(k > sol.size()) return 0;
    REP(i , 0 , k) sum += sol[i].A;
    // DB4("now = " , now , "sum = " , sum);
    if(sum > money) return 0;
    else {
        v.clear();
        REP(i , 0 , k){
            int id = sol[i].B;
            if(x[id][0] == 1) v.pb(mp(id , tma));
            if(x[id][0] == 2) v.pb(mp(id , tmb));
        }
        return 1;
    }
}
int32_t main(){
    IOS;
    cin >> n >> m >> k >> money;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];
    REP(i , 1 , m + 1) REP(j , 0 , 2) cin >> x[i][j];
    int ans = 0;
    RREP(i , 20 , 0){
        int to = ans + (1 << i);
        if(to > n) continue;
        if(judge(to) == 0) ans = to; 
    }
    if(ans == n) cout << -1 << endl;
    else {
        cout << ans + 1 << endl;
        for(auto to : v) cout << to.A << " " << to.B << endl;
    }
    return 0;
}