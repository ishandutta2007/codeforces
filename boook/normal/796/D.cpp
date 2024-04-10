/*input
6 3 2
1 5 6
1 2
1 3
1 4
1 5
5 6
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX] , dis[MAX] , e[MAX][2];
vector<int> v[MAX];
struct djs{
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return x[now]; }
} ds;
int32_t main(){
    ds.init();
    cin >> n >> m >> k;
    REP(i , 1 , m + 1) cin >> x[i];
    REP(i , 1 , n + 1) dis[i] = INF; 
    REP(i , 1 , n + 0){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
        e[i][0] = a , e[i][1] = b;
    }
    queue<int> pq;
    REP(i , 1 , m + 1){
        pq.push(x[i]);
        dis[x[i]] = 0;
    }
    while(pq.size()){
        int now = pq.front(); pq.pop();
        for(auto to : v[now]){
            if(dis[to] > dis[now] + 1){
                dis[to] = dis[now] + 1;
                ds.Union(to , now);
                pq.push(to);
            }
        }
    }
    int cnt = 0;
    vector<int> sol;
    // REP(i , 1 , n + 1) cout << ds[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << dis[i] << " " ; cout << endl;
    REP(i , 1 , n + 0){
        if(ds[e[i][0]] != ds[e[i][1]]){
            sol.pb(i);
            cnt ++;
        }
    }
    cout << cnt << endl;
    for(auto to : sol) cout << to << " "; cout << endl;
    return 0;
}