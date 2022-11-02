/*input
1 4
4
1 1 1 1
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX];
int32_t main(){
    IOS;
    int ans = 0;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , m + 1) cin >> b[i];
    int apo = 1 , bpo = 1;
    int v1 = a[1] , v2 = b[1];
    while(apo <= n || bpo <= m){
        if(v1 == v2){
            ans ++;
            apo = apo + 1 , v1 = a[apo];
            bpo = bpo + 1 , v2 = b[bpo];
        }
        else if(v1 < v2){
            apo ++ , v1 += a[apo];
        }
        else if(v1 > v2){
            bpo ++ , v2 += b[bpo];
        }
    }
    cout << ans << endl;
    return 0;
}