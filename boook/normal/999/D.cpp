/*input
6 3
3 2 0 6 10 12
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900 
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int a){ return Find(a); }
} ds;

int n , m , x[MAX];
vector<int> v[MAX];
int query(int from , int to){
    int tmp = to - from;
    if(tmp < 0) tmp += m;
    return tmp;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) v[x[i] % m].pb(i);
    int ans = 0;

    ds.init();
    REP(i , 0 , m) if(v[i].size() >= n / m) ds.Union(i , (i + 1) % m);
    // REP(i , 0 , m) cout << ds.x[i] << " "; cout << endl;
    REP(i , 0 , m){
        while(v[i].size() > n / m){
            int nxt = ds[i];
            // cout << nxt << endl;
            x[v[i].back()] += query(i , nxt);
            ans += query(i , nxt);
            v[nxt].pb(v[i].back());
            v[i].pop_back();
            if(v[nxt].size() == n / m){
                ds.Union(nxt , (ds[nxt] + 1) % m);
            }
        // REP(j , 0 , m) cout << v[j].size() << " " ; cout << endl;
        }
    }
    cout << ans << endl;
    REP(i , 1 , n + 1) cout << x[i] << " " ;cout << endl;
    return 0;
}