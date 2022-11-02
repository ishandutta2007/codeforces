/*input
3
1 5 3
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

int n , a[MAX] , x[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 0 , n) x[i] = a[i + 1] - a[i];
    vector<int> ans;
    REP(i , 1 , n + 1){
        map<int , int> cc;
        int ok = 1;
        REP(j , 0 , n){
            if(cc.find(j % i) != cc.end() && cc[j % i] != x[j]) ok = 0;
            cc[j % i] = x[j];
            if(ok == 0) break;
        }
        if(ok) ans.pb(i);
    }
    cout << ans.size() << endl;
    for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}