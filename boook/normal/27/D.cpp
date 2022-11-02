/*input
6 3
1 3
3 5
5 1
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000
#define INF 0x3f3f3f3f

int n , m , x[MAX][2] , use[MAX] , scc[MAX] , sccpo = 0;
vector<int> G1[MAX] , G2[MAX] , p;
void DFS1(int now){
    if(use[now]) return ;
    use[now] = 1;
    for(auto to : G1[now]) DFS1(to);
    p.pb(now);
}
void DFS2(int now){
    if(scc[now]) return ;
    scc[now] = sccpo;
    for(auto to : G2[now]) DFS2(to);
}
int trs(int now){ return now <= m ? now + m : now - m; }
int IN(int a , int b , int c){
    return (a < c && c < b);
}
void ADDE(int a , int b){
    G1[a].pb(b);
    G2[b].pb(a);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , m + 1) REP(j , 0 , 2) cin >> x[i][j];
    REP(i , 1 , m + 1) REP(j , 0 , 2) if(x[i][0] > x[i][1]) swap(x[i][0] , x[i][1]);
    REP(i  ,1 , m + 1){
        int a = x[i][0] , b = x[i][1];
        REP(j , i + 1 , m + 1){
            int c = x[j][0] , d = x[j][1];
            if(a != c && a != d && b != c && b != d && IN(a , b , c) != IN(a , b , d)){
                ADDE(i , trs(j));
                ADDE(trs(i) , j);
                ADDE(j , trs(i));
                ADDE(trs(j) , i);
            }
            else if(a == c && b == d){
                ADDE(i , trs(j));
                ADDE(trs(i) , j);
                ADDE(j , trs(i));
                ADDE(trs(j) , i);
            }
        }
    }
    REP(i , 1 , m + m + 1) DFS1(i); 
    RREP(i , p.size() - 1 , 0) if(scc[p[i]] == 0) sccpo ++ , DFS2(p[i]);

    REP(i , 1 , m + 1) if(scc[i] == scc[i + m])
        return cout << "Impossible" << endl , 0;
    REP(i , 1 , m + 1) cout << (scc[i] > scc[i + m] ? "i" : "o"); cout << endl;
    return 0;
}