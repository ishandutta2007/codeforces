/*input
15 8
1 15 2 14 3 13 4 8 12 5 11 6 10 7 9
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , a[MAX] , p[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) a[i] = x[i] <= m;
    REP(i , 1 , n + 1) p[i] = p[i - 1] + a[i];
    REP(i , 1 , n + 1) p[i] = 2 * p[i] - i;

    // REP(i , 0 , n + 1) cout << p[i] << " " ; cout << endl;
    map<int , int> cc;
    int ans = 0 , idx;
    REP(i , 1 , n + 1) if(x[i] == m) idx = i;

    REP(i , 0 , idx) cc[p[i]] ++;
    // cout << idx << endl;
    // for(auto to : cc) cout << to.A << " " << to.B << endl;
    REP(i , idx , n + 1){
    	ans += cc[p[i]];
    	ans += cc[p[i] - 1];
    	// DB4("ans = " , ans , p[i] , cc[p[i]]);
    }
    cout << ans << endl;
    return 0;
}