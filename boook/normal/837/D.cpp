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
#define MAX 250
#define INF 1000000000000LL

int n , m;
int a[MAX] , b[MAX];
int dp[5050][MAX];
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , n + 1){
		int tmp; cin >> tmp;
		while(tmp % 2 == 0) a[i] ++ , tmp /= 2;
		while(tmp % 5 == 0) b[i] ++ , tmp /= 5;
	}

	REP(i , 0 , 5050) REP(j , 0 , MAX) dp[i][j] = -INF;
	dp[0][0] = 0;

	REP(i , 1 , n + 1){
		RREP(j , i , 1){
			RREP(k , 5010 , b[i]){
				dp[k][j] = max(dp[k][j] , dp[k - b[i]][j - 1] + a[i]);
			}
		}
	}
	int ans = 0;
	REP(i , 1 , 5010){
		ans = max(ans , min(i , dp[i][m]));
	}
	cout << ans << endl;
    return 0;
}