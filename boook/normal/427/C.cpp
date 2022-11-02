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
#define int long long
#define MAX 400000
#define INF 1000000000000000LL
#define mod 1000000007LL

int n , m;
int val[MAX];
VI G1[MAX] , G2[MAX] , g;
int scc[MAX] , use[MAX] , sccpo = 0;
void ADDE(int a , int b){
    G1[a].pb(b);
    G2[b].pb(a);
}
void DFS1(int now){
    if(use[now]) return;
    use[now] = 1;
    for(auto to : G1[now]) DFS1(to);
    g.pb(now);
}
void DFS2(int now){
    if(scc[now]) return;
    scc[now] = sccpo;
    for(auto to : G2[now]) DFS2(to);
}
void solveinit(){
    REPNM(i , 1 , n + 1) DFS1(i);
    RREP(i , g.size() - 1 , 0){
        if(scc[g[i]] == 0){
            sccpo ++ , DFS2(g[i]);
        }
    }
}
int mm[MAX] , res[MAX];
int32_t main(){
    cin >> n;
    REPNM(i , 1 , n + 1) cin >> val[i];
    cin >> m;
    REPNM(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        ADDE(a , b);
    }
    solveinit();
    REPNM(i , 1 , sccpo + 1) mm[i] = INF;
    REPNM(i , 1 , n + 1){
        int tmp = scc[i];
        mm[tmp] = min(mm[tmp] , val[i]);
    }
    int sum = 0 , way = 1;
    REPNM(i , 1 , sccpo + 1){
        sum += mm[i];
    }
    REPNM(i , 1 , n + 1){
        int tmp = scc[i];
        if(mm[tmp] == val[i]) res[tmp] ++;
    }
    REPNM(i , 1 , sccpo + 1){
        way = (way * res[i]) % mod;
    }
    cout << sum << " " << way << endl;
    return 0;
}