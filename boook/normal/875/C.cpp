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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m;
vector<int> v[MAX] , G1[MAX] , G2[MAX] , p;
int scc[MAX] , use[MAX] , sccpo;
void DFS1(int now){
    if(use[now]) return ;
    use[now] = 1;
    for(auto to : G1[now]) DFS1(to);
    p.pb(now);
}
void DFS2(int now){
    if(scc[now]) return;
    scc[now] = sccpo;
    for(auto to : G2[now]) DFS2(to);
}
int ADDE(int a , int b){
    // DB4("add" , a , b , "");
    G1[a].pb(b);
    G2[b].pb(a);
}
int N;
int32_t main(){
    cin >> n >> m;
    N = m;
    REP(i , 1 , n + 1){
        int tmp , vv;
        cin >> tmp;
        REP(j , 1 , tmp + 1) cin >> vv , v[i].pb(vv);
    }
    REP(i , 1 , n){
        int sml = min(v[i].size() , v[i + 1].size());
        int id = -1 , a , b;
        REP(j , 0 , sml){
            if(v[i][j] != v[i + 1][j]){
                id = j , a = v[i][j] , b = v[i + 1][j];
                break;
            }
        }
        if(id == -1){
            if(v[i].size() <= v[i + 1].size());
            else return cout << "No" << endl , 0;
        }
        else {
            // DB4("a = " , a , "b = " , b);
            if(a < b){
                ADDE(a + N , b + N);
                ADDE(b , a);
            }
            else {
                ADDE(a + N , a);
                ADDE(b , b + N);
            }
        }
    }

    REP(i , 1 , m + m + 1) DFS1(i);
    RREP(i , p.size() - 1 , 0){
        if(scc[p[i]] == 0){
            sccpo ++;
            DFS2(p[i]);
        }
    }

    // for(auto to : p) cout << to << " " ; cout << endl;
    // cout << "sCC  ";
    // REP(i , 1 , m + m + 1) cout << scc[i] << " " ; cout << endl;
    int ok = 1;
    REP(i , 1 , m + 1){
        if(scc[i] == scc[i + N]) ok = 0;
    }
    if(ok == 0) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        vector<int> sol;
        REP(i , 1 , m + 1){
            if(scc[i] > scc[i + N]) sol.pb(i);
        }
        cout << sol.size() << endl;
        for(auto to : sol) cout << to << " " ; cout << endl;
    }
    return 0;
}