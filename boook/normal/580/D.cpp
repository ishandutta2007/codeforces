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
#define MAX 18
#define INF 0x3f3f3f3f

int dp[MAX][(1 << MAX)];
int n , m , k;
int val[MAX] , cc[MAX][MAX];
int DP(int now , int pic){
    if(dp[now][pic] != -1) return dp[now][pic];
    if(pic == 0) return dp[now][pic] = val[now];
    bitset<MAX> tmp(pic);
    dp[now][pic] = val[now];
    REP(i , 0 , MAX){
        if(tmp.test(i)){
            int qq = cc[now][i];
            dp[now][pic] = max(dp[now][pic] , val[now] + qq + DP(i , pic ^ (1 << i)));
        }
    }
    return dp[now][pic];
}
int32_t main(){
    MEM(dp , -1);
    cin >> n >> m >> k;
    REP(i , 0 , n) cin >> val[i];
    REP(i , 0 , k){
        int q , w , e;
        cin >> q >> w >> e;
        cc[q - 1][w - 1] = e;
    }
    int ans = 0;
    REP(i , 1 , (1 << n)){
        bitset<MAX> tmp(i);
        int cnt = tmp.count();
        if(cnt != m) continue;
        REP(j , 0 , MAX){
            if(tmp.test(j) == 1) ans = max(ans , DP(j , i ^ (1 << j)));
        }
    }
    cout << ans << endl;
    return 0;
}