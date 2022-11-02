/*input
7
1 3 5 15 3 105 35
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int u[MAX] , cnt[MAX] , two[MAX] , n , x[MAX];
int32_t main(){
    u[1] = 1;
    REP(i , 1 , MAX) for(int j = i + i ; j < MAX ; j += i) u[j] -= u[i];
    two[0] = 1;
    REP(i , 1 , MAX) two[i] = two[i - 1] * 2 % mod;

    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i] , cnt[x[i]] ++;

    int ans = 0;
    REP(i , 1 , MAX){
        if(u[i] == 0) continue;
        int tmp = 0 , val;
        for(int j = i ; j < MAX ; j += i) tmp += cnt[j];
        val = (two[tmp] + mod - 1) % mod * u[i] % mod;
        ans = ((ans + val) % mod + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}