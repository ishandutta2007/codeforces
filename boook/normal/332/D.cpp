/*input
6 1
-1 -1 -1 8 -1
-1 5 -1 -1
-1 -1 3
-1 -1
-1
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
#define int int_fast64_t
#define MAX 2020
#define INF 0x3f3f3f3f

int n , k , o[MAX] , c[MAX][MAX];
__float128 v[MAX];
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 1 , n + 1) o[i] --;
    REP(i , 1 , n + 1) REP(j , i + 1 , n + 1){
        cin >> c[i][j];
        if(c[i][j] != -1) o[i] ++ , o[j] ++ , c[i][j];
    }
    __float128 ans = 0;
    REP(i , k - 1 , n){
        v[i] = (__float128)k / (n - k + 1);
        // DB4("v[" , i , "] = " , (double)(v[i]));
        REP(j , 0 , k - 1) v[i] = v[i] * (i - j) / (n - j);
        // DB4("v[" , i , "] = " , (double)(v[i]));
    }
    REP(i , 1 , n + 1) REP(j , i + 1 , n + 1) if(c[i][j] > 0){
        if(o[i] >= k - 1) ans += v[o[i]] * c[i][j];// , DBGG(c[i][j] , (double)v[o[i]]);
        if(o[j] >= k - 1) ans += v[o[j]] * c[i][j];// , DBGG(c[i][j] , (double)v[o[j]]);
    }
    cout << ((long long)(ans + 1e-9)) << endl;
    return 0;
}