/*input
2
2 1
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
#define MAX 600000
#define INF 0x3f3f3f3f

int n;
vector<int> v[MAX];
void DFS(int now , int fa , int deep , vector<int> &sol){
    if(v[now].size() == 1 && v[now][0] == fa) sol.pb(deep);
    else {
        for(auto to : v[now]){
            if(to != fa) DFS(to , now , deep + 1 , sol);
        }
    }
}
int32_t main(){
    IOS , cin >> n;
    REP(i , 1 , n){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int ans = 0;
    for(auto to : v[1]){
        vector<int> sol;
        DFS(to , 1 , 1 , sol);
        sort(ALL(sol));
        ans = max(ans , sol[0]);
        REP(i , 1 , sol.size()){
            sol[i] = max(sol[i] , sol[i - 1] + 1);
            ans = max(ans , sol[i]);
        }
    }
    cout << ans << endl;
    return 0;
}