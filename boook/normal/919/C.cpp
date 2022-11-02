/*input
3 3 1
.*.
*.*
.*.
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , m , k , x[MAX][MAX];
string s[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , n) cin >> s[i];
    int ans = 0;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) x[i][j] = s[i - 1][j - 1] == '.';
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) x[i][j] += x[i][j - 1];
    REP(i , 1 , n + 1){
        REP(j , k , m + 1){
            if(x[i][j] - x[i][j - k] == k) ans ++;
        }
    }
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) x[i][j] = s[i - 1][j - 1] == '.';
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) x[i][j] += x[i - 1][j];
    REP(i , k , n + 1){
        REP(j , 1 , m + 1){
            if(x[i][j] - x[i - k][j] == k) ans ++;
        }
    }
    if(k == 1) cout << ans / 2 << endl;
    else cout << ans << endl;
    return 0;
}