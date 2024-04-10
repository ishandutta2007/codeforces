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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k;
int in[MAX] , out[MAX] , dep[MAX] , lca[MAX][20] , po = 1;
vector<int> v[MAX] , sp[MAX][20];
void DFS(int now , int fa , int deep){
    lca[now][0] = fa;
     in[now] = po ++;
    dep[now] = deep;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS(to , now , deep + 1);
    }
    out[now] = po ++;
}
int FA(int a , int b){
    return in[a] <= in[b] && out[a] >= out[b];
}
int LCA(int a , int b){
    if(FA(a , b)) return a;
    RREP(i , 19 , 0){
        int to = lca[a][i];
        if(FA(to , b) == 0) a = to;
    }
    return lca[a][0];
}
vector<int> Merge(vector<int> a , vector<int> b){
    vector<int> ans;
    ans.resize(a.size() + b.size());
    merge(ALL(a) , ALL(b) , ans.begin());
    while(ans.size() > 10) ans.pop_back();
    return ans;
}
void solveinit(){
    DFS(1 , 0 , 1) , out[0] = po ++;
    REP(i , 1 , n + 1) sort(ALL(sp[i][0]));
    REP(i , 1 , n + 1) while(sp[i][0].size() > 10) sp[i][0].pop_back();
    REP(j , 1 , 20){
        REP(i , 1 , n + 1){
            int to = lca[i][j - 1];
            lca[i][j] = lca[to][j - 1];
             sp[i][j] = Merge(sp[i][j - 1] , sp[to][j - 1]);
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 2 , n + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i , 1 , m + 1){
        int in; cin >> in;
        sp[in][0].pb(i);
    }
    
    solveinit();

    REP(times , 1 , k + 1){
        int a , b , c;
        cin >> a >> b >> c;
        int mid = LCA(a , b) , to;
        // DB4("LCA" , a , b , mid);
        vector<int> ans = sp[mid][0];
        RREP(i , 19 , 0){
            to = lca[a][i];
            if(dep[to] >= dep[mid]) ans = Merge(ans , sp[a][i]) , a = to;
            to = lca[b][i];
            if(dep[to] >= dep[mid]) ans = Merge(ans , sp[b][i]) , b = to;
        }
        cout << min(int(ans.size()) , c) << " ";
        REP(i , 0 , min(int(ans.size()) , c))
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}