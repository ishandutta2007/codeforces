/*input
10
1 2
2 3
3 4
5 6
6 7
7 4
8 9
9 10
10 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define ALL(i) i.begin() , i.end()
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 5050
#define INF 0x3f3f3f3f

int n;
bitset<MAX> all , dp;
vector<int> v[MAX] , ans;
int DFS1(int now , int fa){
    int son = 0;
    vector<int> sol;
    for(auto to : v[now]) if(to != fa){
        int res = DFS1(to , now);
        son += res;
        sol.pb(res);
    }
    sol.pb(n - 1 - son);
    dp.reset() , dp[0] = 1;
    for(auto to : sol) dp |= dp << to;
    all |= dp;
    return son + 1;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 2 , n + 1){
        int v1 , v2; cin >> v1 >> v2;
        v[v1].pb(v2) , v[v2].pb(v1);
    }
    DFS1(1 , 1);
    REP(i , 1 , n - 1) if(all.test(i)) ans.pb(i);
    cout << ans.size() << endl;
    for(auto to : ans) cout << to << " " << n - 1 - to << endl;
    return 0;
}