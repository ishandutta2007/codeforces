/*input
5
2 1
1 0
2 0
3 2
0 3
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
#define int long long
#define MAX 400900

int DIS(PII x , PII y){
	return abs(x.A - y.A) + abs(x.B - y.B);
}
int n , dp[MAX][2] , x[MAX][2];

PII att[MAX][2];
set<int> st;
map<int , vector<PII>> vv;
int cmp(PII x , PII y){
	if(x.A != y.A) return x.A < y.A;
	if(x.A == y.A) return x.B > y.B;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	REP(i , 1 , n + 1) st.insert(max(x[i][0] , x[i][1]));
	REP(i , 1 , n + 1) vv[max(x[i][0] , x[i][1])].pb(x[i][0] , x[i][1]);

	int pos = 1 , ans = 0;
	for(auto to : st){
		sort(ALL(vv[to]) , cmp);
		att[pos][0] = vv[to][0];
		att[pos][1] = vv[to].back();
		// for(auto val : vv[to]) DBGG(val.A , val.B);
		// DB4(att[pos][0].A , att[pos][0].B , att[pos][1].A , att[pos][1].B);
		int dis = DIS(att[pos][0] , att[pos][1]);

		dp[pos][0] = min(
			dp[pos - 1][0] + DIS(att[pos - 1][0] , att[pos][1]) + dis,
			dp[pos - 1][1] + DIS(att[pos - 1][1] , att[pos][1]) + dis);
		dp[pos][1] = min(
			dp[pos - 1][0] + DIS(att[pos - 1][0] , att[pos][0]) + dis,
			dp[pos - 1][1] + DIS(att[pos - 1][1] , att[pos][0]) + dis);
		ans = min(dp[pos][0] , dp[pos][1]);

		// DBGG(dp[pos][0] , dp[pos][1]);
		pos ++;
	}
	cout << ans << endl;
    return 0;
}