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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , x[MAX + 10] , dp[MAX + 10];

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n){
        int q , w;
        cin >> q >> w;
        x[q] = w;
    }
    int ans = 0;
    REP(i , 0 , MAX){
        if(i == 0) dp[i] = (x[i] != 0);
        else if(x[i] == 0) dp[i] = dp[i - 1];
        else if(i - x[i] - 1 < 0) dp[i] = 1;
        else dp[i] = dp[i - x[i] - 1] + 1;
        ans = max(ans , dp[i]);
    }
    cout << n - ans << endl;
    return 0;
}