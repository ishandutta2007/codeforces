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
#define int long long
#define MAX 100090
#define INF 10000000000000000LL

int a , b , c , d , n;
int x[MAX] , use[MAX] , dv[MAX];
int F(int nn , int q){
    // DB4(36 , "" , nn , q);
    MEM(use , 0);
    int po = 0 , ans = 10000000000000000LL;
    REP(i , nn){
        stack<int> cc;
        REP(j , po){
            int tmc = dv[j] * x[i];
            if(tmc >= q) ans = min(ans , tmc);
            if(tmc < MAX && use[tmc] == 0) use[tmc] = 1 , cc.push(tmc);
        }
        if(use[x[i]] == 0) use[x[i]] = 1 , cc.push(x[i]);
        while(cc.size()){
            dv[po ++] = cc.top();
            if(cc.top() >= q)ans = min(ans , cc.top());
            cc.pop();
        }
    }
    // DBGG("end = " , ans);
    return (ans == 10000000000000000LL) ? -2 : ans;
}
int solve(int q , int w){
    if(q < w) swap(q , w);
    int tmp = min(n , 50LL) , ans = INF;
    RREP(i , tmp , 1){
        int qq = F(i , q);
        if(qq == -2) break;
        int xxx = qq * w , now = 1;
        REP(j , i){
            now *= x[j];
            if(now >= xxx){
                ans = min(ans , i);
                break;
            }
        }
    }
    return ans;
}
int32_t main(){
    cin >> a >> b >> c >> d >> n;
    REP(i , n) cin >> x[i];
    sort(x , x + n , greater<int>());
    int ans = INF;
    if(a <= c && b <= d) ans = 0;
    if(a <= d && b <= c) ans = 0;

    int tma = (a % c == 0) ? a / c : a / c + 1;
    int tmb = (b % d == 0) ? b / d : b / d + 1;
    if(a <= c) tma = 0;
    if(b <= d) tmb = 0;
    // DBGG(tma , tmb);
    ans = min(ans , solve(tma , tmb));

    tma = (a % d == 0) ? a / d : a / d + 1;
    tmb = (b % c == 0) ? b / c : b / c + 1;
    if(a <= d) tma = 0;
    if(b <= c) tmb = 0;
    ans = min(ans , solve(tma , tmb));

    if(ans == INF) cout << -1 << "\n" ;
    else cout << ans << endl;
    return 0;
}