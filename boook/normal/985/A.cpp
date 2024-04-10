/*input
10
1 2 3 4 5
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

int n , x[MAX];
int32_t main(){
    IOS;
    cin >> n , n /= 2;
    REP(i , 1 , n + 1) cin >> x[i];
    sort(x + 1 , x + 1 + n);
    int v1 = 1 , v2 = 2;
    int c1 = 0 , c2 = 0;
    REP(i , 1 , n + 1){
        c1 += abs(v1 - x[i]);
        c2 += abs(v2 - x[i]);
        v1 += 2 , v2 += 2;
    }
    cout << min(c1 , c2) << endl;
    return 0;
}