/*input
5
0 1 1 2 2
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

int n , x[MAX] , lim[MAX] , a[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i] , x[i] ++;

    lim[n] = x[n];
    RREP(i , n - 1 , 1) lim[i] = max(lim[i + 1] - 1 , x[i]);
    REP(i , 2 , n + 1) lim[i] = max(lim[i - 1] , lim[i]);

    // REP(i , 1 , n + 1) cout << lim[i] << " "; cout << endl;
    // REP(i , 1 , n + 1) cout << a[i] << " "; cout << endl;

    a[1] = 1;
    REP(i , 2 , n + 1) a[i] = max(a[i - 1] , lim[i]);
    int ans = 0;
    REP(i , 1 , n + 1){
        ans += a[i] - x[i];
    }
    cout << ans << endl;
    return 0;
}