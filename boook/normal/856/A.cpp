/*input
3
3
1 10 100
1
1
2
2 4
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int t , n , x[MAX] , use[MAX];
int32_t main(){
    cin >> t;
    REP(times , 1 , t + 1){
        cin >> n;
        MEM(use , 0);
        REP(i , 1 , n + 1) cin >> x[i];
        vector<int> ans;
        REP(i , 1 , 1000000 + 1){
            if(use[i]) continue;
            ans.pb(i);
            if(ans.size() == n) break;
            REP(j , 1 , n + 1){
                REP(k , 1 , n + 1){
                    int tmp = i + x[j] - x[k];
                    if(1 <= tmp && tmp <= 1000000) use[tmp] = 1;
                }
            }
        }
        if(ans.size() == n){
            cout << "YES" << endl;
            for(auto to : ans) cout << to << " " ; cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}