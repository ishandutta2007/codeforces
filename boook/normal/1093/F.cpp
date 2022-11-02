/*input
10 42 7
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100009
#define INF 0x3f3f3f3f
#define mod 998244353LL

int dp[MAX][110];
int allsum = 0 , sum[110];
queue<PII> qu[110];

int n , k , len , x[MAX];
void U(int &now , int val){
	now = (now + val) % mod;
	now = (now + mod) % mod;
}
void add(int i , int j){
	qu[j].push(mp(i , dp[i][j]));
	// DB4("add = " , i , j , dp[i][j]);
	U(sum[j] , dp[i][j]);
	U(allsum , dp[i][j]);
}
void str(int i){
	// DB4("str = " , qu[i].front().F , i , qu[i].front().S);
	U(sum[i] , -qu[i].front().S);
	U(allsum , -qu[i].front().S);
	qu[i].pop();
}
int32_t main(){
	IOS;
	cin >> n >> k >> len;
	REP(i , 1 , n + 1) cin >> x[i];

	if(len == 1) return cout << 0 << endl , 0;

	REP(i , 1 , k + 1) if(x[1] == i || x[1] == -1){
		dp[1][i] = 1;
		add(1 , i);
	}

	REP(i , 2 , n + 2){
		// DB4("now i = ========================" , i , "fixed = " , qu[3].front().F);
		REP(j , 1 , k + 1) while(qu[j].size() && i - qu[j].front().F >= len) str(j);
		if(i == n + 1) return cout << allsum << endl , 0;
		
		if(x[i] == -1){
			REP(j , 1 , k + 1) U(dp[i][j] , allsum - sum[j]);
			REP(j , 1 , k + 1) add(i , j);
		}
		if(x[i] != -1){
			U(dp[i][x[i]] , allsum - sum[x[i]]);
			add(i , x[i]);
			REP(j , 1 , k + 1) while(qu[j].size() && j != x[i]) str(j);
		}
	}
    return 0;
}