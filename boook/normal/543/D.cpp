/*input
5
1 2 3 4
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , dp[MAX] , pre[MAX];
vector<int> v[MAX] , fr[MAX] , ba[MAX];
void DFS1(int now , int fa){
	dp[now] = 1;
	for(auto to : v[now]){
		DFS1(to , now);
		dp[now] = (dp[now] * (dp[to] + 1)) % mod;
		fr[now].pb(dp[now]);
	}
	int tmp = 1;
	stack<int> cc;
	RREP(i , (int)v[now].size() - 1 , 0){
		int to = v[now][i];
		tmp = tmp * (dp[to] + 1) % mod;
		cc.push(tmp);
	}
	while(cc.size()) ba[now].pb(cc.top()) , cc.pop();
}
int GET(int now , int id , int ty){
	if(id == -1 || v[now].size() == id) return 1;
	if(ty == 0) return fr[now][id];
	if(ty == 1) return ba[now][id];
}
void DFS2(int now , int fa){
	int all = (pre[now] + 1) % mod;
	REP(i , 0 , v[now].size()){
		int to = v[now][i];
		pre[to] = GET(now , i - 1 , 0) * GET(now , i + 1 , 1) % mod * all % mod;
		DFS2(to , now);
	}
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 2 , n + 1){
		int in; cin >> in;
		v[in].pb(i);
	}
	DFS1(1 , 0);
	DFS2(1 , 0);
	REP(i , 1 , n + 1){
		cout << dp[i] * (1 + pre[i]) % mod << " ";
	}
	cout << endl;
    return 0;
}