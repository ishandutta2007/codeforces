/*input
27 30893
19 16 7 4 21 9 5 20 12 17 26 11 15 24 23 2 3 18 27 10 22 8 14 6 13 1 25
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
#define MAX 50090
#define INF 0x3f3f3f3f
#define N 32

int k , in , n , mod , dp[N][N][MAX] , x[MAX] , id[MAX];
int32_t main(){
	IOS;
	cin >> k >> mod;
	REP(i , 1 , k + 1){
		cin >> in;
		if(in < N) x[++ n] = in , id[n] = i;
	}
	REP(i , 0 , n){
		REP(j , 0 , N){
			REP(p , 0 , mod){
				if(dp[i][j][p]){
					int val = ((x[i + 1] > 9 ? (p * 100) : p * 10) + x[i + 1]) % mod;
					dp[i + 1][j ^ x[i + 1]][val] = 1;
					dp[i + 1][j][p] = 1;
				}
			}
		}
		dp[i + 1][x[i + 1]][x[i + 1] % mod] = 1;
	}
	// REP(i , 1 , n + 1) REP(j , 0 , N) REP(p , 0 , mod) if(dp[i][j][p]) DB4(i , j , p , "");
	if(dp[n][0][0]){
		cout << "Yes" << endl;
		int now = 0 , pat = 0;
		vector<int> sol;
		RREP(i , n , 1){
			// DB4("now = " , now , pat , dp[i][now][pat]);
			if(dp[i - 1][now][pat]);
			else if(now == x[i] && pat == x[i] % mod){
				sol.pb(id[i]);
				break;
			}
			else {
				sol.pb(id[i]);
				int ok = 0;
				REP(j , 0 , N) {
					if((j ^ x[i]) != now || ok) continue;
					REP(p , 0 , mod){
						int val = ((x[i] > 9 ? p * 100 : p * 10) + x[i]) % mod;
						if(val == pat && dp[i - 1][j][p] && ok == 0){
							now = j , pat = p , ok = 1;
						}
					}
				}
			}
		}
		cout << sol.size() << endl;
		reverse(ALL(sol));
		for(auto to : sol) cout << to << " " ; cout << endl;
	}
	else cout << "No" << endl;
    return 0;
}