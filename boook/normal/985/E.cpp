/*input
6 3 10
7 2 7 7 4 2
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
#define MAX 500900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX] , dp[MAX] , pre[MAX];
int query(int l , int r){
    l = max(l , 0);
    if(l > r) return 0;
    else if(l == 0) return pre[r] > 0;
    else return pre[r] - pre[l - 1] > 0;
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    sort(x + 1 , x + 1 + n);

    dp[0] = pre[0] = 1;
    int pos = 1;
    REP(i , 1 , n + 1){
        while(x[i] - x[pos] > k) pos ++;
        dp[i] = query(pos - 1 , i - m);
        // DB4("i = " , i , "pos = " , pos);
        // DB4("dp[" , i , "] = " , dp[i]);
        pre[i] = pre[i - 1] + dp[i];
    }
    if(dp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}