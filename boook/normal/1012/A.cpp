/*input
3
1 3 3 3 4 4
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , a[MAX];
int32_t main(){
    IOS;
    cin >> n;
    int nn = n + n;
    REP(i , 1 , nn + 1) cin >> a[i];
    sort(a + 1 , a + nn + 1);
    
    int v1 = a[ n] - a[    1];
    int v2 = a[nn] - a[n + 1];
    int ans = v1 * v2;
    REP(i , 2 , n + 1){
        int to = i + n - 1;
        if(to == nn) break;
        else ans = min(ans , (a[to] - a[i]) * (a[nn] - a[1]));
    } 
    cout << ans << endl;
    return 0;
}