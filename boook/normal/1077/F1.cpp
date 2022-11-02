/*input
5 2 3
5 1 3 10 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
const int MAX = 5050;
const int INF = 1e17;

int n , m , k , dp[MAX][MAX] , x[MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i];

	REP(i , 0 , n + 1) REP(j , 0 , n + 1) dp[i][j] = -INF;
	dp[0][0] = 0;

	int ans = -INF;
	REP(j , 1 , k + 1){
		deque<int> dq; dq.push_back(0);
		REP(i , 1 , n + 1){
			while(dq.size() && i - dq[0] > m) dq.pop_front();
			if(dq.size()) dp[j][i] = dp[j - 1][dq[0]] + x[i];

			while(dq.size() && dp[j - 1][dq.back()] <= dp[j - 1][i])
				dq.pop_back();
			dq.push_back(i);

			// DB4(j , i , " = " , dp[j][i]);
			if(n + 1 - i <= m) ans = max(ans , dp[j][i]);
		}
	}

	cout << (ans < 0 ? -1 : ans) << endl;
    return 0;
}