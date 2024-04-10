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
typedef long long LL;
#define MAX 2000900
#define INF 0x3f3f3f3f

int dv[MAX] , ppo = 0 , pp[MAX];
void pre(){
    dv[0] = dv[1] = 1;
    REPNM(i , 2 , MAX){
        if(dv[i] == 0) pp[ppo++] = i , dv[i] = i;
        REP(j , ppo){
            LL tmp = pp[j];
            if(tmp * i >= MAX) break;
            dv[tmp * i] = tmp;
            if(i % tmp == 0) break;
        }
    }
}

int n , m , val[MAX];
int ans[MAX] , nt[MAX] , dep[MAX];
VI v[MAX];
void DFS(int now , int fa , int deep){
    dep[now] = deep;
    VI num , sty;
    int tmp = val[now];
    while(tmp != 1) {
        int res = dv[tmp];
        num.pb(res);
        while(tmp % res == 0) tmp /= res;
    }
    REP(i , num.size()){
        if(dep[ans[now]] < dep[nt[num[i]]]) ans[now] = nt[num[i]];  
        sty.pb(nt[num[i]]) , nt[num[i]] = now;
    }
    for(auto to : v[now]) if(to != fa) DFS(to , now , deep + 1);
    REP(i , num.size()) nt[num[i]] = sty[i];
}
int32_t main(){
    IOS;
    pre();
    cin >> n >> m;
    int q , w;
    REPNM(i , 1 , n + 1) cin >> val[i];
    REPNM(i , 1 , n) cin >> q >> w , v[q].pb(w) , v[w].pb(q);
    DFS(1 , -1 , 1);
    // REPNM(i , 1 , n + 1) DBGG(i , ans[i]);
    REPNM(i , 1 , m + 1){
        cin >> q;
        if(q == 1){
            cin >> w;
            cout << ans[w] - (ans[w] == 0) << "\n";
        }
        if(q == 2) cin >> q >> w , val[q] = w , MEM(ans , 0) , DFS(1 , -1 , 1);
    }
    return 0;
}