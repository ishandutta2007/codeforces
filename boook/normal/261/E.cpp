/*input
2 111 100
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
#define MAX 3000000
#define INF 0x3f3f3f3f
#define N 1000000000

int p[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 
           59 , 61 , 67 , 71 , 73 , 79 , 83 , 89 , 97};
vector<int> v;
void DFS(int now , int get){
    v.pb(now);
    REP(i , 0 , get + 1) if(1LL * now * p[i] <= N) DFS(now * p[i] , i);
}
int dp[MAX] , sml[MAX];
int32_t main(){
    IOS;
    DFS(1 , 24) , sort(ALL(v));
    REP(i , 0 , v.size()) dp[i] = sml[i] = INF;
    dp[0] = 0;
    REP(i , 2 , 100){
        int pos = 0;
        REP(j , 1 , v.size()){
            if(v[j] % i != 0) continue;
            while(v[pos] < v[j] / i) pos ++;
            dp[j] = min(dp[j] , dp[pos] + 1);    
            sml[j] = min(sml[j] , dp[j] + i);
        }
    }
    int ans = 0 , l , r , k;
    cin >> l >> r >> k;
    REP(i , 0 , v.size()) if(l <= v[i] && v[i] <= r && sml[i] <= k) ans ++;
    cout << ans << endl;
    return 0;
}