/*input
6 1
1 2
1 3
1 4
1 5
1 6
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
#define MAX 1000090
#define INF 0x3f3f3f3f

int n , k , dp[MAX] , ans;
vector<int> v[MAX];
void DFS(int now , int fa){
    if(v[now].size() == 1 && v[now][0] == fa)
        return dp[now] = 0 , void();

    vector<int> sol;    
    for(auto to : v[now]) if(to != fa){
        DFS(to , now);
        sol.pb(dp[to] + 1);
    }
    sort(ALL(sol) , greater<int>());
    dp[now] = -INF;
    REP(i , 0 , sol.size()){
        if(i + 1 < sol.size()){
            if(sol[i] + sol[i + 1] > k){
                // DBGG("here" , now);
                ans ++;
            }
            else dp[now] = max(dp[now] , sol[i]);
        }
        else{
            if(sol[i] > k){
                ans ++;
                // DBGG("here" , now);
            }
            else dp[now] = max(dp[now] , sol[i]);
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 2 , n + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int idx = -1;
    REP(i , 1 , n + 1) if(v[i].size() == 1) idx = i;
    if(k == 0){
        REP(i , 1 , n + 1) ans += v[i].size() == 1;
        cout << ans << endl;
    }
    else {
        DFS(idx , idx);
    // REP(i , 1 , n + 1) DBGG(i , dp[i]);
        ans ++;
        cout << ans << endl;
    }
    return 0;
}