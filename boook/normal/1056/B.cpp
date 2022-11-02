/*input
3 3
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

int n , m , x[MAX];

int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , m){
        if(i == 0)
             x[i * i % m] += n / m;
        else x[i * i % m] += n / m + (n % m >= i);
    //     DBGG(i , i * i % m);
    // REP(j , 0 , m) cout << x[j] << " "; cout << endl;
    } 
    // REP(i , 1 , n + 1) x[i * i % m] ++;
    int ans = 0;
    REP(i , 0 , m) ans += x[i] * x[(m - i) % m];
    cout << ans << endl;
    return 0;
}