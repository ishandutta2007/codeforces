/*input
7
1 2
2 3
2 4
4 5
4 6
5 7		
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
#define MAX 200900
#define INF 0x3f3f3f3f


int n , use[MAX] , dp[MAX][3];
vector<int> v[MAX];
void DFS(int now , int fa , int deep){
	if(deep <= 2) use[now] = 1;
	for(auto to : v[now]) if(to != fa) DFS(to , now , deep + 1);
}
void DFS1(int now , int fa){
	dp[now][0] = 0;   // uncover
	// dp[now][1] = INF; // cover not choose
	// if(use[now] == 0) dp[now][1] = INF;
	// if(use[now] == 1) dp[now][1] = 0;
	dp[now][2] = 1;   // choose
	
	int sml = 0;
	for(auto to : v[now]) if(to != fa) DFS1(to , now);
	for(auto to : v[now]) if(to != fa) dp[now][0] += dp[to][1];

	if(use[now] == 0) dp[now][1] = INF;
	else {
		dp[now][1] = 0;
		for(auto to : v[now]) if(to != fa) dp[now][1] += dp[to][1];
	}
	for(auto to : v[now]) if(to != fa) sml += min(dp[to][1] , dp[to][2]);

	for(auto to : v[now]) if(to != fa) 
		dp[now][1] = min(dp[now][1] , sml - min(dp[to][1] , dp[to][2]) + dp[to][2]);

	for(auto to : v[now]) if(to != fa) 
		dp[now][2] += min(dp[to][0] , min(dp[to][1] , dp[to][2]));
	// DB4(now , dp[now][0] , dp[now][1] , dp[now][2]);
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
 	DFS(1 , 1 , 0);
	DFS1(1 , 1);
	int ans = min(dp[1][1] , dp[1][2]);
	cout << ans << endl;
    return 0;
}