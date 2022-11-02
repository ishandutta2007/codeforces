/*input
1 1 3
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int v1 , v2 , n;
map<PII , int> dp;
int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a , k >> 1);
    if(k % 2 == 1) return ppow(a * a , k >> 1) * a;
}
int DP(int a , int b){
    if(dp.find(mp(a , b)) != dp.end()) return dp[mp(a , b)];
    else {
        if(a == 1 && ppow(2 , b) >= n) return dp[mp(a , b)] = 0;
        if(b == 1 && a * a >= n){
            if(n % 2 != a % 2) return dp[mp(a , b)] = -1;
            if(n % 2 == a % 2) return dp[mp(a , b)] =  1;
        }
        dp[mp(a , b)] = -1;
        if(ppow(a + 1 , b) < n) dp[mp(a , b)] = max(dp[mp(a , b)] , -DP(a + 1 , b));
        if(ppow(a , b + 1) < n) dp[mp(a , b)] = max(dp[mp(a , b)] , -DP(a , b + 1));
        return dp[mp(a , b)];
    }
}
int32_t main(){
    IOS;
    cin >> v1 >> v2 >> n;
    int ans = DP(v1 , v2);
    // for(auto to : dp) cout << to.A.A << " " << to.A.B << " " << to.B << endl;
    if(ans == -1) cout << "Stas" << endl;
    if(ans ==  0) cout << "Missing" << endl;
    if(ans ==  1) cout << "Masha" << endl;
    return 0;
}