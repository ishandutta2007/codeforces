/*input
2 2
1
1 1 -1
100
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

int n , m , k , x[MAX][MAX] , mod , two[MAX];
int sw;
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    if(n % 2 != m % 2) return cout << 0 << endl , 0;
    if(n < m) swap(n , m) , sw = 1;
    REP(i , 1 , k + 1){
        int v1 , v2 , v3;
        cin >> v1 >> v2 >> v3;
        if(sw) swap(v1 , v2);
        x[v1][v2] = v3;
    }
    cin >> mod;
    two[0] = 1;
    REP(i , 1 , n + 1) two[i] = two[i - 1] * 2 % mod;
    int ans = 1 , zero = 0;
    REP(i , 1 , n + 1){
        int cnt = 0 , val = 1;
        REP(j , 1 , m + 1){
            if(x[i][j] == 0) cnt ++;
            else val *= x[i][j];
        }
        if(cnt == m && zero == 0) zero = 1;
        else if(cnt == 0){
            if(val != -1) return cout << 0 << endl , 0;
        }
        else ans = ans * two[cnt - 1] % mod;
    }
    cout << ans << endl;
    return 0;
}