/*input
4 5
1 2 R
1 3 R
2 3 B
3 4 B
1 4 B
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
#define MAX 200900
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX]; 
    void init(){ REP(i , 0 , MAX) x[i] = i;}
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(max(a , b))] = Find(min(a , b)); }
    int operator[](int now){ return Find(now); }
} ds;
int n , m , a[MAX][2] , ans = INF;
char c[MAX];
vector<int> v , sol[MAX];
void solve(){
    ds.init();
    REP(i , 1 , m + 1){
        if(c[i] == 'R'){
            if(ds[a[i][0] * 2 + 0] == ds[a[i][1] * 2 + 1]) return;
            ds.Union(a[i][0] * 2 + 0 , a[i][1] * 2 + 0);
            ds.Union(a[i][0] * 2 + 1 , a[i][1] * 2 + 1);
        }
        else {
            if(ds[a[i][0] * 2 + 0] == ds[a[i][1] * 2 + 0]) return;
            ds.Union(a[i][0] * 2 + 0 , a[i][1] * 2 + 1);
            ds.Union(a[i][1] * 2 + 0 , a[i][0] * 2 + 1);
        }
    }
    // cout << "here" << endl;

    REP(i , 0 , MAX) sol[i].clear();
    vector<int> tmp;
    REP(i , 1 , n + 1){
        sol[ds[i * 2 + 1]].pb(i * 2 + 1);
    }
    REP(i , 1 , n + 1){
        if(ds[i * 2 + 0] == i * 2){
            int q = sol[ds[i * 2 + 0]].size();
            int w = sol[ds[i * 2 + 1]].size();
            // DB4("now = " , i , q , w);
            if(q <= w){
                for(auto to : sol[ds[i * 2 + 0]])
                    tmp.pb(to / 2);
            }
            else {
                for(auto to : sol[ds[i * 2 + 1]])
                    tmp.pb(to / 2);
            }
        }
    }
    if(tmp.size() < ans) ans = tmp.size() , v = tmp;
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , m + 1) cin >> a[i][0] >> a[i][1] >> c[i];
    solve();
    REP(i , 1 , m + 1) c[i] = (c[i] == 'R') ? 'B' : 'R';
    solve();

    if(ans == INF) cout << -1 << endl;
    else{
        cout << ans << endl;
        for(auto to : v) cout << to << " " ; cout << endl;
    }
    return 0;
}