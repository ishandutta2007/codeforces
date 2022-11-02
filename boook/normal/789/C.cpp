/*input
50
-5 -9 0 44 -10 37 34 -49 11 -22 -26 44 8 -13 23 -46 34 12 -24 2 -40 -15 -28 38 -40 -42 -42 7 -43 5 2 -11 10 43 9 49 -13 36 2 24 46 50 -15 -26 -6 -6 8 4 -44 -3
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , sol[MAX] , a[MAX] , b[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 0) sol[i] = abs(x[i] - x[i + 1]);

    REP(i , 1 , n + 0){
        if(i % 2 == 0) a[i] = a[i - 1] + sol[i];
        if(i % 2 == 1) a[i] = a[i - 1] - sol[i];
    }
    REP(i , 1 , n + 0){
        if(i % 2 == 0) b[i] = b[i - 1] - sol[i];
        if(i % 2 == 1) b[i] = b[i - 1] + sol[i];
    }
    int sml = INF , ans = 0;
    REP(i , 1 , n + 0){
        if(i % 2 == 1) sml = min(sml , a[i]);
        ans = max(ans , a[i] - sml);
    }
    sml = 0;
    REP(i , 1 , n + 0){
        if(i % 2 == 0) sml = min(sml , b[i]);
        ans = max(ans , b[i] - sml);
    }
    cout << ans << endl;
    // REP(i , 1 , n + 1) cout << sol[i] << " " ; cout << endl;
    return 0;
}