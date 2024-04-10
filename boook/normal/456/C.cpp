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

int n , dp[MAX] , cnt[MAX] , x;

int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x , cnt[x] ++;
    int ans = cnt[1];
    dp[1] = cnt[1];
    REP(i , 1 , MAX){
        dp[i] = max(dp[i - 1] , dp[i - 2] + cnt[i] * i);
        ans = max(ans , dp[i]);
    }
    cout << ans << endl;
    return 0;
}