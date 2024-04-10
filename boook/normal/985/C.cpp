/*input
10 3 453
277 706 727 812 692 686 196 507 911 40 498 704 573 381 463 759 704 381 693 640 326 405 47 834 962 521 463 740 520 494
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
#define MAX 100900
#define INF 0x3f3f3f3f
// 40 47 196 277 326 381 381 405 463 463 
// 494 498 507 520 521
// 573 640 686 692 693 704 704 706 727 740 759 812 834 911 962 
int n , m , k , x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n * m + 1) cin >> x[i];
    sort(x + 1 , x + 1 + n * m);
    // REP(i , 1 , n * m + 1) cout << x[i] << " " ; cout << endl;
    int base = x[1] , to = 1;
    while(to + 1 <= n * m && x[to + 1] - base <= k) to ++;
    if(to < n) return cout << 0 << endl , 0;
    else {
        int cnt = 0 , ans = 0;
        while(n - cnt + cnt * m < to) ans += x[cnt * m + 1] , cnt ++;
        RREP(i , to , 1) if(cnt < n) cnt ++ , ans += x[i];
        cout << ans << endl;
    }
    return 0;
}