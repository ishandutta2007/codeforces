/*input
4 3 6
1 2
1 3
2 2
2 3
3 1
3 3
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
#define MAX 200900
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX] , have[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i , have[i] = 0; }
    int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int a){ return Find(a); }
} ds;

int n , m , k , ok[MAX] , u[MAX] , use[MAX] , non[MAX];
PII x[MAX];
set<PII> cc;
vector<int> v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    ds.init();

    REP(i , 1 , k + 1) cin >> x[i].A >> x[i].B;
    REP(i , 1 , k + 1) v[x[i].A].pb(x[i].B);
    REP(i , 1 , n + 1) if(v[i].size()){
        for(auto to : v[i]) ds.Union(v[i][0] , to);
    }
    REP(i , 1 , k + 1) if(x[i].A == 1){
        int to = ds[x[i].B];
        ds.have[to] = 1;
    }
    REP(i , 1 , k + 1) non[x[i].A] = 1;

    int ans = 0;
    REP(i , 1 , m + 1) ans += ds[i] == i && ds.have[i] == 0;
    REP(i , 2 , n + 1) if(non[i] == 0) ans ++;
    cout << ans << endl;
    return 0;
}