/*input
0 5 2
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
#define MAX 
#define INF 0x3f3f3f3f

int n , m , k;
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    int ans = 0 , fr = 0;
    REP(i , 1 , n + 1){
        int a , b;
        cin >> a >> b;
        b = a + b;

        int tmp = a - fr;
        ans += tmp / k;
        fr = b;
    }
    ans += (m - fr) / k;
    cout << ans << endl;
    return 0;
}