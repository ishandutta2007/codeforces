/*input
1000000000000 1000000000001
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
#define MAX 
#define INF 0x3f3f3f3f

int n , k;
int32_t main(){
    IOS;
    cin >> n >> k;
    if(k <= 1) return cout << 0 << endl , 0;
    if(k / 2 <= n && k - k / 2 <= n){
        int l;
        if(1 <= k - 1 && k - 1 <= n) l = 1;
        else l = k - n;
        int r = min(k - 1 , n);
        // DBGG(l , r);
        int ans = r - l + 1;
        if(k % 2 == 0) ans --;
        cout << ans / 2 << endl;
    }
    else cout << 0 << endl;
    return 0;
}