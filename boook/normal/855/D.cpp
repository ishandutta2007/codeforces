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
#define MAX 100090
#define INF 0x3f3f3f3f

vector<PII> v[MAX];

int n , m;
int in[MAX] , out[MAX] , po = 1;
int sp[MAX][20] , pre[MAX] , dep[MAX];
void DFS(int now , int fa , int deep){
    sp[now][0] = fa;
    in[now] = po ++;
    dep[now] = deep;
    for(auto to : v[now]){
        if(to.A == fa) continue;
        pre[to.A] = pre[now] + to.B;
        DFS(to.A , now , deep + 1);
    }
    out[now] = po ++;
}
int early(int a , int b){
    return in[a] <= in[b] && out[a] >= out[b];
}
int LCA(int a , int b){
    if(early(a , b)) return a;
    RREP(i , 19 , 0){
        if(early(sp[a][i] , b) == 0) a = sp[a][i];
    }
    return sp[a][0];
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1){
        int a , b;
        cin >> a >> b;
        if(a == -1) a = n + 1 , b;
        v[a].pb(mp(i , b));
    }
    DFS(n + 1 , 0 , 1) , out[0] = po ++;

    REP(i , 1 , 20){
        REP(j , 1 , n + 2){
            sp[j][i] = sp[sp[j][i - 1]][i - 1];
        }
    }
    cin >> m;
    REP(times , 1 , m + 1){
        int a , b , c;
        cin >> a >> b >> c;
        int lca = LCA(b , c);
        if(lca == n + 1 || b == c) cout << "NO" << endl;
        else {
            int ok = 0;

            if(a == 1){
                if(lca == b && pre[lca] == pre[c]) ok = 1;
            }
            if(a == 2){
                if(pre[lca] == pre[b] && pre[c] - pre[lca] == dep[c] - dep[lca] && dep[c] != dep[lca]) ok = 1;
            }
            if(ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}