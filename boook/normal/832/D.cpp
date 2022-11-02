#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , pa[MAX] , dep[MAX];
int sp[MAX][20];
vector<int> v[MAX];

void DFS(int now , int fa , int deep){
    dep[now] = deep;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS(to , now , deep + 1);
    }
}
void solveinit(){
    REP(i , 1 , n + 1) sp[i][0] = pa[i];
    REP(i , 1 , 20){
        REP(j , 1 , n + 1){
            sp[j][i] = sp[sp[j][i - 1]][i - 1];
        }
    }
}
int LCA(int a , int b){
    if(dep[a] != dep[b]){
        if(dep[a] < dep[b]) swap(a , b);
        RREP(i , 19 , 0){
            int to = sp[a][i];
            if(dep[to] >= dep[b]) a = to;
        }
    }
    if(a == b) return a;
    RREP(i , 19 , 0){
        int ato = sp[a][i];
        int bto = sp[b][i];
        if(ato != bto) a = ato , b = bto;
    }
    return sp[a][0];
}
int dis(int a , int b){
    return dep[a] + dep[b] - 2 * dep[LCA(a , b)];
}
int32_t main(){
    cin >> n >> m;
    REP(i , 2 , n + 1){
        cin >> pa[i];
        int q = i , w = pa[i];
        v[q].pb(w) , v[w].pb(q);
    }
    DFS(1 , 0 , 1);
    solveinit();
    REP(i , 1 , m + 1){
        int a , b , c;
        cin >> a >> b >> c;
        int q = LCA(a , b) , w = LCA(b , c) , e = LCA(c , a);
        // DB4(q , w , e , "LCA");
        if(dep[q] < dep[w]) q = w;
        if(dep[q] < dep[e]) q = e;
        int ans = 0;
        ans = max(ans , dis(q , a));
        ans = max(ans , dis(q , b));
        ans = max(ans , dis(q , c));
        cout << ans + 1 << endl;
    }
    return 0;
}