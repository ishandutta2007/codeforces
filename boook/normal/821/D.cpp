/*input
5 10 5
1 1
3 2
5 8
3 6
1 8
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 400000
#define INF 0x3f3f3f3f

int n , m , k;
int a[MAX] , b[MAX] , x[MAX][2] , po = 2 , dis[MAX];
vector<PII> v[MAX];
map<PII , int> cc;
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
void dijkstra(){
    priority_queue<PII , vector<PII> , greater<PII> > pq;
    pq.push(mp(0 , cc[mp(1 , 1)]));
    MEM(dis , INF) , dis[cc[mp(1 , 1)]] = 0;
    while(pq.size()){
        int step = pq.top().A;
        int now = pq.top().B;
        pq.pop();
        if(dis[now] != step) continue;
        // DB4("dis[ " , now , " ] = " , dis[now]);
        for(auto to : v[now]){
            if(dis[to.A] > dis[now] + to.B){
                dis[to.A] = dis[now] + to.B;
                pq.push(mp(dis[to.A] , to.A));
            }
        }
    }
}
int32_t main(){
    cin >> n >> m >> k;
    REP(i , 1 , k + 1) REP(j , 0 , 2) cin >> x[i][j];
       
    REP(i , 1 , n + 1) a[i] = po ++;
    REP(i , 1 , m + 1) b[i] = po ++;
    // REP(i , 1 , n + 1) cout << a[i] << " "; cout << endl;
    // REP(i , 1 , m + 1) cout << b[i] << " " ; cout << endl;
    REP(i , 1 , k + 1) {
        cc[mp(x[i][0] , x[i][1])] = po ++;
        // cout << po << " ";
    }

    REP(i , 1 , k + 1){
        PII now = mp(x[i][0] , x[i][1]);
        REP(j , 0 , 4){
            int tox = x[i][0] + X[j];
            int toy = x[i][1] + Y[j];
            PII to = mp(tox , toy);
            if(cc.find(to) != cc.end()){
                v[cc[now]].pb(mp(cc[to] , 0));
            }
        }
        REP(j , -1 , 2){
            v[cc[now]].pb(mp(a[x[i][0] + j] , 1));
            v[a[x[i][0] + j]].pb(mp(cc[now] , 0));

            v[cc[now]].pb(mp(b[x[i][1] + j] , 1));
            v[b[x[i][1] + j]].pb(mp(cc[now] , 0));
        }
    }
    v[0].clear();
    dijkstra();
    int ans = INF;
    if(cc.find(mp(n , m)) != cc.end())
        ans = min(ans , dis[cc[mp(n , m)]]);
    ans = min(ans , dis[a[n]]);
    ans = min(ans , dis[b[m]]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}