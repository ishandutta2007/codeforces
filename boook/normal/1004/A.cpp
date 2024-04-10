/*input
5 2
4 8 11 18 19
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
#define int long long
#define MAX 1010
#define INF 0x3f3f3f3f

int ans = 0;
set<int> dd;
int n , m , x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i] , dd.insert(x[i]);
    set<int> cc;
    REP(i , 1 , n + 1) cc.insert(x[i] - m);
    REP(i , 1 , n + 1) cc.insert(x[i] + m);
    for(auto to : cc){
        auto ba = dd.lower_bound(to);
        if(ba != dd.end() && abs((*ba) - to) < m) continue;
        if(ba != dd.begin() && abs((*prev(ba)) - to) < m) continue;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}