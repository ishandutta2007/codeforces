#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 500
#define INF 0x3f3f3f3f

int n , a[MAX][MAX] , b[MAX];
int pre[2][MAX];
int one[MAX] , two[MAX];
int32_t main(){
    cin >> n;
    REP(i , 0 , 2) REP(j , 1 , n) cin >> a[i][j];
    REP(i , 1 , n + 1) cin >> b[i];

    REP(i , 1 , n + 1) pre[0][i] = pre[0][i - 1] + a[0][i - 1];
    REP(i , 1 , n + 1) pre[1][i] = pre[1][i - 1] + a[1][i - 1];


    REP(i , 1 , n + 1){
        one[i] = pre[0][i] + b[i] + pre[1][n] - pre[1][i];
        // DBGG("onw[i] = " , pre[1][i - 1]);
    }
    int ans = one[1] + one[2];
    REP(i , 1 , n + 1){
        REP(j , i + 1 , n + 1){
            ans = min(ans , one[i] + one[j]);
        }
    }
    cout << ans << endl;
    return 0;
}