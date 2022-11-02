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
#define MAX 110
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , k , d;
int dp[MAX][MAX];
int32_t main(){
	cin >> n >> k >> d;
	dp[0][0] = 1;
	REP(i , 0 , n){
		REP(j , 0 , k + 1){
			REP(o , 1 , k + 1){
				if(i + o < MAX)
					dp[i + o][max(o , j)] = (dp[i + o][max(o , j)] + dp[i][j]) % mod;
			}
		}
	}
	int ans = 0;
	REP(i , d , k + 1) ans = (ans + dp[n][i]) % mod;
	cout << ans << endl;
    return 0;
}