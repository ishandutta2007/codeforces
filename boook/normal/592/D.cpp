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
#define MAX 234567
#define INF 0x3f3f3f3f

int n , m , x[MAX] , use[MAX];
VI v[MAX];
int DFS1(int now , int fa){
    int cnt = 0;
    for(auto to : v[now]){
        if(to == fa) continue;
        cnt += DFS1(to , now);
    }
    if(cnt || x[now]) return use[now] = 1;
    else return use[now] = 0;
}
PII DFS2(int now , int fa){
    PII mm = mp(now , 0);
    for(auto to : v[now]){
        if(to == fa || use[to] == 0) continue;
        PII tmp = DFS2(to , now);
        if(tmp.B + 1 > mm.B) mm = mp(tmp.A , tmp.B + 1);
        else if(tmp.B + 1 == mm.B) mm.A = min(mm.A , tmp.A);
    }
    return mm;
}
int32_t main(){
    cin >> n >> m;
    int q , w;
    REPNM(i , 1 , n) cin >> q >> w , v[q].pb(w) , v[w].pb(q);
    REP(i , m) cin >> q , x[q] = 1;
    DFS1(q , -1);

    PII tma = DFS2(q , -1);
    PII tmp = DFS2(tma.A , -1);

    int cnt = 0;
    REPNM(i , 1 , n + 1) cnt += use[i];
    cout << min(tma.A , tmp.A) << "\n";
    cout << (cnt - 1) * 2 - tmp.B << "\n";
    return 0;
}