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
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 2010
#define INF 0x3f3f3f3f
#define debug 1

VI G1[MAX] , G2[MAX] , g;
int n , use[MAX] , scc[MAX] , sccpo = 0;
void DFS1(int now){
    if(use[now]) return ;
    use[now] = 1;
    for(auto to : G1[now]) DFS1(to);
    g.pb(now);
}
void DFS2(int now){
    if(scc[now]) return ;
    scc[now] = sccpo;
    for(auto to : G2[now]) DFS2(to);
}
int main(){
    
    IOS;
    cin >> n;

    int tmp;
    REPNM(i , 1 , n + 1){
        REPNM(j , 1 , n + 1){
            cin >> tmp;
            if(tmp) G1[i].pb(j) , G2[j].pb(i);
        }
    }

    REPNM(i , 1 , n + 1) DFS1(i);
    RREP(i , g.size() - 1 , 0)
        if(scc[g[i]] == 0) ++sccpo , DFS2(g[i]);

    if(sccpo == 1) puts("YES");
    if(sccpo != 1) puts("NO");
    return 0;
}