/*input
4 3
0 1 0 1
0 1
1 2
2 3
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

int n , m , x[MAX] , o[MAX] , u[MAX];
vector<int> v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> x[i];
    REP(i , 0 , m){
        int a , b;
        cin >> a >> b;
        v[b].pb(a) , o[a] ++;
    }
    queue<int> sol , zero;

    int ok = 0 , ans = 0;

    REP(i , 0 , n) if(o[i] == 0 && x[i] == 0) zero.push(i);
    REP(i , 0 , n) if(o[i] == 0 && x[i] == 1) sol.push(i);

    while(zero.size()){
        int now = zero.front(); zero.pop();
        u[now] = 1 , ok ++;
        for(auto to : v[now]){
            o[to] --;
            if(o[to] == 0){
                if(x[to] == 0) zero.push(to);
                if(x[to] == 1) sol.push(to);
            }
        }
    }

    while(ok != n){
        // cout << ok << endl;
        // REP(i , 0 , n) cout << u[i] << " " ; cout << endl;
        // REP(i , 0 , n) cout << o[i] << " " ; cout << endl;
        ans ++;
        queue<int> zero;
        while(sol.size()){
            int now = sol.front(); sol.pop();
            u[now] = 1 , ok ++;
            for(auto to : v[now]){
                o[to] --;
                if(o[to] == 0){
                    if(x[to] == 0) zero.push(to);
                    if(x[to] == 1) sol.push(to);
                }
            }
        }
        while(zero.size()){
            int now = zero.front(); zero.pop();
            u[now] = 1 , ok ++;
            for(auto to : v[now]){
                o[to] --;
                if(o[to] == 0){
                    if(x[to] == 0) zero.push(to);
                    if(x[to] == 1) sol.push(to);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}