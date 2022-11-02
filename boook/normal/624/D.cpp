/*input
8 3 4
3 7 5 4 3 12 9 4
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
#define INF 10000000000000000LL
// before a
// a
// after a
int n , a , b , x[MAX] , dp[MAX][4];
int solve(int val){
    REP(i , 1 , n + 1){
    	dp[i][0] = dp[i][1] = dp[i][2] = INF;

        if(x[i] % val == 0) dp[i][0] = min(dp[i][0] , dp[i - 1][0]);
        if((x[i] + 1) % val == 0 || (x[i] - 1) % val == 0)
        	dp[i][0] = min(dp[i][0] , dp[i - 1][0] + b);

        dp[i][1] = min(dp[i - 1][0] + a , dp[i - 1][1] + a);

        if(x[i] % val == 0){
        	dp[i][2] = min(dp[i][2] , dp[i - 1][1]);
        	dp[i][2] = min(dp[i][2] , dp[i - 1][2]);
        }
        if((x[i] + 1) % val == 0 || (x[i] - 1) % val == 0){
        	dp[i][2] = min(dp[i][2] , dp[i - 1][1] + b);
        	dp[i][2] = min(dp[i][2] , dp[i - 1][2] + b);
        }
    }
    return min(dp[n][0] , min(dp[n][1] , dp[n][2]));
}
int32_t main(){
    cin >> n >> a >> b;
    REP(i , 1 , n + 1) cin >> x[i];
    set<int> cc;
    int val , ans = INF;
    REP(iii , -1 , 1 + 1){
    	int val = x[1] + iii;
	    REP(i , 2 , val + 1){
	        if(i * i > val) break;
	        else if(val % i == 0){
	            cc.insert(i);
	            while(val % i == 0) val /= i;
	        }
	    }
	    if(val != 1) cc.insert(val);

	    val = x[n] + iii;
	    REP(i , 2 , val + 1){
	        if(i * i > val) break;
	        else if(val % i == 0){
	            cc.insert(i);
	            while(val % i == 0) val /= i;
	        }
	    }
	    if(val != 1) cc.insert(val);
    }

    for(auto to : cc) ans = min(ans , solve(to));
    cout << ans << endl;
    return 0;
}