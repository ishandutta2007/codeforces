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
#define MAX 1000090
#define INF 0x3f3f3f3f

int n , x[MAX] , dp[MAX] , ans;
inline int rit(){
    int res = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res;
}
int32_t main(){
    n = rit();
    REP(i , 1 , n + 1) x[i] = rit();
    sort(x + 1 , x + 1 + n);
    REP(i , 1 , n + 1){
        dp[x[i]] ++;
        for(int j = x[i] ; j < MAX ; j += x[i]){
            dp[j] = max(dp[j] , dp[x[i]]);
            ans = max(ans , dp[j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}