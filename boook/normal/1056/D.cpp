/*input
5
1 1 3 3
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , p[MAX] , x[MAX] , ans[MAX] , cnt[MAX];
vector<int> v[MAX];
void DFS(int now){
    if(v[now].size() == 0) x[now] = 1;
    else {
        for(auto to : v[now]){
            DFS(to);
            x[now] += x[to];
        }
    }
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 2 , n + 1) cin >> p[i];
    REP(i , 2 , n + 1) v[p[i]].pb(i);
    DFS(1);
    REP(i , 1 , n + 1) cnt[x[i]] ++;
    REP(i , 1 , n + 1) cnt[i] += cnt[i - 1];
    REP(i , 1 , n + 1) ans[i] = INF;
    REP(i , 1 , n + 1) ans[cnt[i]] = min(ans[cnt[i]] , i);
    RREP(i , n - 1 , 1) ans[i] = min(ans[i + 1] , ans[i]);
    REP(i , 1 , n + 1) cout << ans[i] << " " ;cout << endl;
    return 0;
}