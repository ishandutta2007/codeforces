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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m , dir[5] , pa[MAX][MAX];
int x[] = {0 , -1 , 1 ,  0 , 0};
int y[] = {0 ,  0 , 0 , -1 , 1};
char Z[5] = {' ' , 'U' , 'D' , 'L' , 'R'};
VI way;
PII now;
string p[MAX];

void setdir(int a , int b){ dir[a] = b; }
void GO(int d){ printf("%c\n" , Z[dir[d]]); fflush(stdout); }
void GET(){ cin >> now.A >> now.B; now.A -- , now.B --; }

void finddir(){
    if(p[0][0] == 'F') return ;
    now = mp(0 , 0);

    if(n > 1 && p[1][0] != '*'){
        GO(2) , GET();
        if(now.A == 0 && now.B == 0) setdir(1 , 2) , setdir(2 , 1);
        if(p[now.A][now.B] == 'F') return;
        int tma = -1;
        if(m > 1){
            REP(i , n){
                if(p[i][0] == '*') break;
                if(p[i][0] != '*' && p[i][1] != '*'){ tma = i;break; }
            }
            if(tma == 0){
                if(now.A != 0) GO(1) , GET();
                GO(4) , GET();
                if(now.B == 0) setdir(3 , 4) , setdir(4 , 3);
            }
            else if(tma != -1){
                while(now.A != tma){
                    GO(2) , GET();
                    if(p[now.A][now.B] == 'F') return;
                }
                GO(4) , GET();
                if(now.B == 0) setdir(3 , 4) , setdir(4 , 3);
            }
        }
    }
    else if(m > 1 && p[0][1] != '*'){
        GO(4) , GET();
        if(now.A == 0 && now.B == 0) setdir(3 , 4) , setdir(4 , 3);
        if(p[now.A][now.B] == 'F') return;
        int tma = -1;
        if(n > 1){
            REP(i , m){
                if(p[0][i] == '*') break;
                if(p[0][i] != '*' && p[1][i] != '*'){ tma = i;break; }
            }
            if(tma != -1){
                while(now.B != tma){
                    GO(4) , GET();
                    if(p[now.A][now.B] == 'F') return;
                }
                GO(2) , GET();
                if(now.A == 0) setdir(1 , 2) , setdir(2 , 1);
            }
        }
    }
}
void BFS(){
    MEM(pa , -1) , pa[now.A][now.B] = 1;
    queue<PII> qu; qu.push(now);
    PII nn , res;
    while(qu.size()){
        nn = qu.front(); qu.pop();
        if(p[nn.A][nn.B] == 'F') res = nn;
        REPNM(i , 1 , 4 + 1){
            PII to = mp(nn.A + x[i] , nn.B + y[i]);
            if(to.A >= 0 && to.B >= 0 && to.A < n && to.B < m && p[to.A][to.B] != '*'){
                if(pa[to.A][to.B] == -1) pa[to.A][to.B] = i , qu.push(to);
            }
        }
    }
    while(res != now){
        int qq = pa[res.A][res.B];
        way.pb(qq);
        res.A -= x[qq] , res.B -= y[qq];
    }
}
void solve(){
    finddir();
    if(p[now.A][now.B] == 'F') return ;
    BFS();
    RREP(i , way.size() - 1 , 0) GO(way[i]) , GET();
}
int32_t main(){
    cin >> n >> m;
    REP(i , n) cin >> p[i];
    REPNM(i , 1 , 4 + 1) setdir(i , i);
    solve();
    return 0;
}