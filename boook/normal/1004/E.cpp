/*input
10 3
1 2 5
5 7 2
3 2 6
10 6 3
3 8 1
6 4 2
4 1 6
6 9 4
5 2 5
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
#define int long long
#define MAX 100900
#define INF 1e17

int n , m , nn , e[MAX][3] , u[MAX] , p[MAX] , sol[MAX] , x[MAX];
int fr[MAX] , ba[MAX] , edge[MAX];
vector<int> v[MAX];
PII DFS(int now , int fa , int deep){
    PII ans = mp(deep , now);
    for(auto idx : v[now]){
        int to = e[idx][0] ^ e[idx][1] ^ now , val = e[idx][2];
        if(to != fa) ans = max(ans , DFS(to , now , deep + val));
    }
    return ans;
}
int DFS1(int now , int fa , int wnt){
    if(now == wnt) return ++nn , p[now] = nn , sol[nn] = now;
    for(auto idx : v[now]){
        int to = e[idx][0] ^ e[idx][1] ^ now , val = e[idx][2];
        if(to != fa && DFS1(to , now , wnt))
            return ++nn , p[now] = nn , sol[nn] = now , edge[nn] = val , u[idx] = 1 , 1;
    }
    return 0;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 0) REP(j , 0 , 3) cin >> e[i][j];
    REP(i , 1 , n + 0){
        v[e[i][0]].pb(i);
        v[e[i][1]].pb(i);
    }
    int v1 = DFS( 1 , 0 , 0).B;
    int v2 = DFS(v1 , 0 , 0).B;

    DFS1(v1 , 0 , v2);
    REP(now , 1 , n + 1) if(p[now] != 0){
        for(auto idx : v[now]){
            int to = e[idx][0] ^ e[idx][1] ^ now , val = e[idx][2];
            if(p[to] == 0) x[p[now]] = max(x[p[now]] , DFS(to , now , val).A);
        }
    }


    // DBGG("nn = " , nn);
    // cout << "thing = "; REP(i , 1 , nn + 1) cout << sol[i] << " "; cout << endl;
    // cout << "    x = "; REP(i , 1 , nn + 1) cout << x[i] << " "; cout << endl;
    // cout << "edges = "; REP(i , 1 , nn + 1) cout << edge[i] << " " ; cout << endl;

    REP(i , 1 , nn + 1) fr[i] = ba[i] = x[i];
    REP(i , 2 , nn + 1)  fr[i] = max(fr[i - 1] + edge[i    ] , x[i]);
    RREP(i , nn - 1 , 1) ba[i] = max(ba[i + 1] + edge[i + 1] , x[i]);

    // cout << "fr = " ;
    // REP(i , 1 , nn + 1) cout << fr[i] << " " ; cout << endl;
    // cout << "ba = " ;
    // REP(i , 1 , nn + 1) cout << ba[i] << " " ; cout << endl;
    int big = 0;
    REP(i , 1 , nn + 1) big = max(big , x[i]);
    if(nn <= m) cout << big << endl;
    else {
        // cout << "getans = ";
        int ans = INF , pos = 0;
        REP(i , 1 , nn + 1){
            int to = min(n , i + m - 1);
            // cout << max(*prev(big.end()) , max(fr[i - 1] , ba[to + 1])) << " ";
            ans = min(ans , max(big , max(fr[i] , ba[to])));
        }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}