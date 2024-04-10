/*input
5
1 5 4 3 2
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
#define int long long
#define MAX 200000
#define INF 0x3f3f3f3f

int use[MAX] , n , x[MAX];
int DFS(int now){
    if(use[now]) return 0;
    use[now] = 1;
    return 1 + DFS(x[now]);
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    int cnt = 0;
    vector<int> sol;
    REP(i , 1 , n + 1){
        if(use[i] == 0){
            sol.pb(DFS(i));
        }
    }
    sort(ALL(sol));
    if(sol.size() >= 2){
        int a = sol.back(); sol.pop_back();
        int b = sol.back(); sol.pop_back();
        sol.pb(a + b);
    }
    int ans = 0;
    for(auto to : sol){
        ans += to * to;
    }
    cout << ans << endl;
    return 0;
}