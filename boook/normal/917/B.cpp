/*input
5 8
5 3 h
1 2 c
3 1 c
3 2 r
5 1 r
4 3 z
5 4 r
5 2 h
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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m , dp[MAX][MAX][30];
vector<PII> v[MAX];
int DP(int a , int b , int val){
	if(dp[a][b][val]) return dp[a][b][val];
	dp[a][b][val] = 2;
	for(auto to : v[a]){
		if(to.B >= val && DP(b , to.A , to.B) == 2){
			dp[a][b][val] = 1;
			break;
		}
	}
	return dp[a][b][val];
	// b , to , newval
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		string s;
		cin >> a >> b >> s;
		v[a].pb(mp(b , s[0] - 'a'));
	}
	REP(i , 1 , n + 1){
		REP(j , 1 , n + 1){
			if(DP(i , j , 0) == 1) cout << "A";
			else cout << "B";
		}
		cout << endl;
	}
    return 0;
}