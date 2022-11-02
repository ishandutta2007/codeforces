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
#define MAX 
#define INF 0x3f3f3f3f

int n;
int x[3][2] , ans[3];

int32_t main(){
    cin >> n;
    REP(i , 0 , 3) REP(j , 0 , 2) cin >> x[i][j];
    ans[0] = x[0][0];
    ans[1] = x[1][0];
    ans[2] = x[2][0];
    n = n - ans[0] - ans[1] - ans[2];
    REP(i , 0 , 3){
        int tmp = x[i][1] - x[i][0];
        if(n >= tmp) ans[i] += tmp , n -= tmp;
        else ans[i] += n , n = 0;
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    return 0;
}