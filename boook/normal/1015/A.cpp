/*input
3 5
2 2
1 2
5 5
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , x[MAX];
int32_t main(){
    IOS;
    cin >> m >> n;
    REP(i , 1 , m + 1){
        int l , r;
        cin >> l >> r;
        REP(j , l , r + 1) x[j] = 1;
    }
    int ans = 0;
    REP(i , 1 , n + 1) ans += x[i] == 0;
    cout << ans << endl;
    REP(i , 1 , n + 1) if(x[i] == 0) cout << i << " "; cout << endl;
    return 0;
}