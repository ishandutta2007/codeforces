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
#define MAX 400000
#define INF 1000000000000000LL;

int n , k;
int x[MAX] , dp[5050][5050] , val[MAX] , pre[MAX];
int cost(int l , int r){
    if(l == r) return 0;
    r --;
    return pre[r] - pre[l - 1];
}
int32_t main(){
    
    cin >> n >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    sort(x + 1 , x + n + 1);
    REP(i , 1 , n + 0) val[i] = x[i + 1] - x[i];
    REP(i , 1 , n + 1) pre[i] = pre[i - 1] + val[i];

    int len , sml = 0 , big = 0;
    REP(i , 1 , k + 1){
        int now = i , cnt = 0;
        while(now <= n) now += k , cnt ++;
        if(i == 1) len = cnt;
        if(cnt == len) big ++;
        else if(cnt == len - 1) sml ++;
        else assert(0);
    }
    REP(i , 0 , 5050) REP(j , 0 , 5050) dp[i][j] = INF;
    REP(i , 0 , big + 1){
        REP(j , 0 , sml + 1){
            if(i == 0 && j == 0) dp[i][j] = 0;
            else {
                int now = i * len + j * (len - 1);
                if(j > 0) dp[i][j] = min(dp[i][j] , 
                    dp[i][j - 1] + cost(now - (len - 1) + 1 , now));
                if(i > 0) dp[i][j] = min(dp[i][j] , 
                    dp[i - 1][j] + cost(now - len + 1 , now));
            }
        }
    }
    cout << dp[big][sml] << endl;
    return 0;
}