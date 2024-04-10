/*input
3 7
1 2
3 3
4 7
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

int n , ans = 0 , l , r;

int32_t main(){
    IOS;
    int k;
    cin >> n >> k;

    REP(i , 1 , n + 1){
        int l , r;
        cin >> l >> r;
        ans += r - l + 1;
    }
    if(ans % k == 0) cout << 0 << endl;
    else cout << (ans / k + 1) * k - ans << endl;
    return 0;
}