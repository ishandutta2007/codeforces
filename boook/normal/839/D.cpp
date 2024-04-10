/*input
4
2 3 4 6
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int u[MAX] , two[MAX] , ni = (mod - mod / 2) % mod;
void solveinit(){
    u[1] = two[0] = 1;
    REP(i , 1 , MAX) two[i] = two[i - 1] * 2 % mod;
    REP(i , 1 , MAX) for(int j = i + i ; j < MAX ; j += i) u[j] -= u[i];
}
int n , x[MAX] , cnt[MAX] , sum[MAX] , ans[MAX];
int32_t main(){
    solveinit();
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) cnt[x[i]] ++;

    REP(i , 2 , MAX){
        for(int j = i ; j < MAX ; j += i){
            sum[i] += cnt[j];
        }
    }
    // REP(i , 2 , 10) cout << sum[i] << " " ; cout << endl;
    REP(i , 2 , MAX){
        sum[i] = two[sum[i]] * sum[i] % mod * ni % mod;
    }
    REP(i , 2 , MAX){
        for(int j = i ; j < MAX ; j += i){
            ans[i] = (ans[i] + u[j / i] * sum[j] + mod) % mod;
        }
    }
    int res = 0;
    REP(i , 2 , MAX) res = (res + ans[i] * i) % mod;
    cout << res << endl;
    return 0;
}