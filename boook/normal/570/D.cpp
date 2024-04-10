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
#define MAX 500010
#define INF 0x3f3f3f3f

int n , m , N;
string s;
int dep[MAX] , b[MAX] , po = 0 , l[MAX] , r[MAX];
VI v[MAX] , sol;
PII q[MAX];
bool ans[MAX];
int c[MAX];
void DFS(int now , int deep){
    dep[now] = deep , l[now] = po;
    b[po ++] = now;
    for(auto i : v[now]) DFS(i , deep + 1);
    r[now] = po - 1;
}
void solveinit(){
    DFS(0 , 1);
}
int cmp(int a , int b){
    PII tma = mp(l[q[a].A] , r[q[a].B]);
    PII tmb = mp(l[q[b].A] , r[q[b].B]);
    if(tma.A / N != tmb.A / N) return tma.A / N < tmb.A / N;
    else return tma.B < tmb.B;
}
void ADD(int now){
    // DBGG("now = " , now);
    int tmp = s[b[now]] - 'a';
    // DBGG("befor" , c[dep[now]]);
    c[dep[b[now]]] ^= (1 << tmp);
    // DBGG("after" , c[dep[now]]);
}
int W(int now){
    int cnt = 0;
    while(now) cnt += now % 2 , now /= 2;
    return cnt <= 1;
}
void solve(){
    sort(ALL(sol) , cmp);
    int L = 0 , R = -1;
    for(auto i : sol){
        int now = q[i].A;
        while(l[now] < L) ADD(--L);
        while(L < l[now]) ADD(L++);
        while(r[now] < R) ADD(R--);
        while(R < r[now]) ADD(++R);
        ans[i] = W(c[q[i].B]);
        // DBGG(i , c[q[i].B]);
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , n - 1){
        int tmp;
        cin >> tmp;
        v[tmp - 1].pb(i + 1);
    }
    cin >> s;
    solveinit();
    // REP(i , n) cout << dep[i] << " " ; cout << endl;
    // REP(i , n) cout << l[i] << " " ; cout << endl;
    // REP(i , n) cout << r[i] << " " ; cout << endl;
    REP(i , m){
        int tma , tmb;
        cin >> tma >> tmb;
        if(dep[tma - 1] >= tmb) ans[i] = 1;
        else q[i] = mp(tma - 1 , tmb) , sol.pb(i);
    }
    N = sqrt((int)sol.size() + 1);
    solve();
    // cout << "------------" << endl;
    // for(auto i : sol) cout << i << " " ; cout << endl;
    REP(i , m){
        if(ans[i]) cout << "Yes\n" ;
        else cout << "No\n" ;
    }
    return 0;
}