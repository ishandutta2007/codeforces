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

int n , m , k , x[MAX];
class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
} ds;
vector<int> v[MAX];
int col[MAX];
int32_t main(){
    ds.init();
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        ds.Union(a , b);
    }
    REP(i , 1 , n + 1){
        v[ds[i]].pb(i);
    }
    int ans = 0;
    REP(i , 1 , n + 1){
        if(v[i].empty()) continue;
        int big = 0 , id = 0;
        for(auto to : v[i]){
            col[x[to]] ++;
            if(col[x[to]] > big) big = col[x[to]] , id = x[to];
        }
        for(auto to : v[i]){
            if(x[to] != id) ans ++;
        }
        for(auto to : v[i]) col[x[to]] --;
    }
    cout << ans << endl;
    return 0;
}