/*input
2
4 1
1 2 5
3 1 2
3 4 3
7 2
1 2 5
1 3 4
1 4 2
2 5 1
2 6 2
4 7 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 500009
#define INF 0x3f3f3f3f

int t , n , m;
vector<PII> v[MAX];

int cmp(PII v1 , PII v2){
    return v1.S - v1.F > v2.S - v2.F;
}
PII DFS(int now , int fa , int edge){
    vector<PII> sol;
    for(auto to : v[now]) if(to.F != fa)
        sol.pb(DFS(to.F , now , to.S));

    sort(sol.begin() , sol.end() , cmp);
    PII ans = {0 , edge};
    REP(i , 0 , sol.size()){
        if(i < m) 
             ans.F += max(sol[i].F , sol[i].S);
        else ans.F += sol[i].F;
        if(i < m - 1)
             ans.S += max(sol[i].F , sol[i].S);
        else ans.S += sol[i].F;
    }

    // cout << "now = " << now << " " << ans.F << " " << ans.S << endl;
    return ans;
}
int32_t main(){
    IOS;
    cin >> t;
    REP(times , 0 , t){
        cin >> n >> m;
        REP(i , 2 , n + 1){
            int v1 , v2 , v3;
            cin >> v1 >> v2 >> v3;
            v[v1].pb(v2 , v3);
            v[v2].pb(v1 , v3);
        }
        PII ans = DFS(1 , 1 , 0);

        cout << ans.F << endl;

        REP(i , 1 , n + 1) v[i].clear();
    }    
    return 0;
}