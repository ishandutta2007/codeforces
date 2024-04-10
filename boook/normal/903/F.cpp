/*input
4
10 10 1 10
***.
*..*
*..*
.***
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , dp[MAX][1 << 12] , v[4] , x[MAX][4];
vector<int> p[3] = {{1 , 2 , 4 , 8} , {51 , 102 , 204} , {1911 , 3822}};
//    1 ,    2 ,    4 ,    8
//   16 ,   32 ,   64 ,  128
//  256 ,  512 , 1024 , 2048

int32_t main(){
	cin >> n;
	REP(i , 0 , 4) cin >> v[i];
	REP(j , 0 , 4){
		string s; cin >> s;
		REP(i , 0 , n) x[i][j] = s[i] == '*';
	}
	RREP(i , n + 5 , 0){
		REP(j , 0 , (1 << 12)){
			if(j % 16 == 0){
				int pat = (j >> 4);
				REP(ii , 0 , 4) pat += x[i][ii] * (1 << (8 + ii));
				dp[i][j] = dp[i + 1][pat];
			}
			else {
				dp[i][j] = dp[i + 1][0] + v[3];
				REP(ii , 0 , 3){
					for(auto to : p[ii]){
						dp[i][j] = min(dp[i][j] , dp[i][j & (~to)] + v[ii]);
					}
				}
			}
		}
	}
	cout << dp[0][0] << endl;
    return 0;
}