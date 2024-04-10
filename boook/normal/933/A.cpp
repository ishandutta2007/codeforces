/*input
10
1 1 2 2 2 1 1 2 2 1
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , x[MAX] , one[MAX] , two[MAX] , tt[MAX][MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) if(x[i] == 1) one[i] = 1;
	REP(i , 1 , n + 1) if(x[i] == 2) two[i] = 1;
	REP(i , 1 , n + 1) one[i] += one[i - 1];
	REP(i , 1 , n + 1) two[i] += two[i - 1];

	REP(ii , 1 , n + 1){
		vector<int> sol;
		REP(j , ii , n + 1){
			if(sol.size() == 0 || sol.back() <= x[j]) sol.pb(x[j]);
			else *upper_bound(ALL(sol) , x[j]) = x[j];
			tt[ii][j] = sol.size();
		}
	}
	int ans = tt[1][n];
	REP(i , 1 , n){
		ans = max(ans , tt[1][i] + tt[i + 1][n]);
	}
	cout << ans << endl;
    return 0;
}