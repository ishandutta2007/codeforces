/*input
9
3 2 5 5 2 3 3 3 2
4 1 4 1 1 2 4 4 1
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
#define MAX 
#define INF 0x3f3f3f3f

int n , x;
vector<int> a , b , c , d;
int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> x , a.pb(x);
    REP(i , 0 , n) cin >> x , b.pb(x);
    REP(i , 0 , n) c.pb(a[i]) , c.pb(b[i]);
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));
    REP(i , 0 , n) if(c[i * 2 + 0] != c[i * 2 + 1])
        return cout << -1 << endl , 0;
    multiset<int> cc , dd;
    REP(i , 0 , n) cc.insert(c[i * 2]);
    int ans = 0;
    REP(i , 0 , n){
        if(cc.find(a[i]) == cc.end()) ans ++;
        else cc.erase(cc.find(a[i]));
    }
    cout << ans << endl;
    return 0;
}