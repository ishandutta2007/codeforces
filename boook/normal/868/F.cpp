/*input
13 3
1 2 2 2 1 2 1 1 1 2 2 1 1
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
#define MAX 100900
#define INF 1000000000000000LL
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , x[MAX] , a[MAX] , dp[MAX];
int val = 0 , l = 1 , r = 0 , id , cnt[MAX];
int query(int ql , int qr){
    while(l < ql) cnt[x[l]] -- , val -= cnt[x[l]] , l ++;
    while(ql < l) l -- , val += cnt[x[l]] , cnt[x[l]] ++;
    while(qr < r) cnt[x[r]] -- , val -= cnt[x[r]] , r --;
    while(r < qr) r ++ , val += cnt[x[r]] , cnt[x[r]] ++;
    return val;
}
int solve(int now , int l , int r , int ql , int qr){
    REP(i , ql , min(mid , qr + 1)){
        if(query(i + 1 , mid) + a[i] < dp[mid])
            dp[mid] = query(i + 1 , mid) + a[i] , id = i;
    }
    if(l != r) solve(ls , l , mid + 0 , ql , id);
    if(l != r) solve(rs , mid + 1 , r , id , qr);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) a[i] = query(1 , i);
    REP(i , 2 , m + 1){
        REP(i , 1 , n + 1) dp[i] = INF;
        // REP(i , 1 , n + 1) cout << a[i] << " " ; cout << endl;
        solve(1 , 1 , n , 0 , n - 1);
        REP(i , 1 , n + 1) a[i] = dp[i];
        // cout << endl;
    }
    cout << dp[n] << endl;
    return 0;
}