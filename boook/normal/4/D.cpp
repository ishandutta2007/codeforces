/*input
5 10 10
22 23
17 19
13 17
8 12
2 6
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 5050
#define INF 0x3f3f3f3f

int n , a , b , dp[MAX] , fm[MAX];
PII x[MAX];
map<PII , int> dd;
int32_t main(){
	IOS;
	cin >> n >> a >> b;
	REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
	REP(i , 1 , n + 1) dd[x[i]] = i;
	sort(x + 1 , x + 1 + n);
	REP(i , 1 , n + 1) {
		if(x[i].A > a && x[i].B > b) dp[i] = 1;
		else dp[i] = -INF;
		REP(j , 1 , i) if(x[i].A > x[j].A && x[i].B > x[j].B){
			if(dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				fm[i] = j;
			}
		}
	}
	stack<int> cc;
	int ans = 0 , id = 0;
	REP(i , 1 , n + 1){
		if(dp[i] > ans) ans = dp[i] , id = i;
	}
	cout << ans << endl;
	while(id) cc.push(id) , id = fm[id];
	while(cc.size()) cout << dd[x[cc.top()]] << " " , cc.pop(); cout << endl;
    return 0;
}