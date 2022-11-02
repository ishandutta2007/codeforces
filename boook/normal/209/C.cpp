#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; ++ i)
#define A first
#define B second
#define mp make_pair
#define pb push_back
#define PII pair<int , int>
#define ALL(i) i.begin() , i.end()
#define MEM(i , j) memset(i , j , sizeof i)
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///-----------------------------------------------------------------------------
#define MAX 1000090
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
} ds;

int n , m , o[MAX] , c[MAX] , ok[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    ds.init();
    ok[1] = 1;
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        ds.Union(a , b);
        ok[a] = 1 , o[a] ++;
        ok[b] = 1 , o[b] ++;
        ds.Union(a , b);
    }
    REP(i , 1 , n + 1) if(o[i] % 2 == 1) c[ds[i]] ++;
    vector<int> sol;
    REP(i , 1 , n + 1) if(ok[i] && ds[i] == i) sol.pb(c[i]);
    // for(auto to : sol) cout << to << " " ; cout << endl;
    int cnt = 0 , ans = 0;
    if(sol.size() == 1) cnt += sol[0];
    else {
        for(auto to : sol) cnt += max(0 , to - 2) , ans += 2;
    }
    // DBGG(cnt , ans);
    cout << ans / 2 + cnt / 2 << endl;
    return 0;
}