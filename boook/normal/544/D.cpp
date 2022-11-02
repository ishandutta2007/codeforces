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
#define MAX 3030
#define INF 0x3f3f3f3f

int n , m;
vector<int> v[MAX];
int a[3] , b[3] , dis[MAX][MAX];
void BFS(int from){
    queue<PII> qu;
    qu.push(mp(from , 0));
    dis[from][from] = 0;
    while(qu.size()){
        int now = qu.front().A;
        int step = qu.front().B;
        qu.pop();
        for(auto to : v[now]){
            if(dis[from][to] > step + 1){
                dis[from][to] = step + 1;
                qu.push(mp(to , step + 1));
            }
        }
    }
}
int32_t main(){
    MEM(dis , INF);
    cin >> n >> m;
    REP(i , 1 , m + 1){
        int q , w;
        cin >> q >> w;
        v[q].pb(w) , v[w].pb(q);
    }

    REP(j , 0 , 3) cin >> a[j];
    REP(j , 0 , 3) cin >> b[j];

    REP(i , 1 , n + 1) BFS(i);
    int ans = -1;

    // REP(i , 1 , n + 1){
    //     REP(j , 1 , n + 1) cout << dis[i][j] << " ";cout << endl;
    // }

    if(dis[a[0]][a[1]] <= a[2] && dis[b[0]][b[1]] <= b[2])
        ans = max(ans , m - dis[a[0]][a[1]] - dis[b[0]][b[1]]);

    REP(i , 1 , n + 1) REP(j , i + 1 , n + 1){
        int tma = min(dis[a[0]][i] + dis[i][j] + dis[j][a[1]] , dis[a[0]][j] + dis[j][i] + dis[i][a[1]]);
        int tmb = min(dis[b[0]][i] + dis[i][j] + dis[j][b[1]] , dis[b[0]][j] + dis[j][i] + dis[i][b[1]]);
        if(tma <= a[2] && tmb <= b[2]){
            ans = max(ans , m - tma - tmb + dis[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}