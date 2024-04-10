/*input
6
1 2 4 8 16 32
4
1 6
2 5
3 4
1 2
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , m , x[MAX] , v[MAX][MAX] , u[MAX][MAX];
int DP(int i , int j){
    if(u[i][j] == 0){
        u[i][j] = 1;
        if(i == j) v[i][j] = x[i];
        else v[i][j] = DP(i + 1 , j) ^ DP(i , j - 1);
    }
    return v[i][j];
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) REP(j , i , n + 1) DP(i , j);
    // REP(i , 1 , n + 1) {REP(j , 1 , n + 1) cout << v[i][j] << " ";cout << endl;}
    RREP(i , n , 1) REP(j , 1 , n + 1){
        v[i][j] = max(v[i][j] , v[i + 1][j]);
        v[i][j] = max(v[i][j] , v[i][j - 1]);
    }
    cin >> m;
    REP(i , 1 , m + 1){
        int v1 , v2;
        cin >> v1 >> v2;
        cout << v[v1][v2] << endl;
    }
    return 0;
}