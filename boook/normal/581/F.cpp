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
#define MAX 5050
#define INF 0x3f3f3f3f

int n;
vector<int> v[MAX];
int dp[MAX][MAX] , siz[MAX];
int DFS1(int now , int fa){
	if(v[now].size() == 1 && v[now][0] == fa) return siz[now] = 1;
	int cnt = 0;
	for(auto to : v[now])
		if(to != fa) cnt += DFS1(to , now);
	return siz[now] = cnt;
}
void DFS2(int now , int fa){
	MEM(dp[now] , INF) , dp[now][0] = 0;
	for(auto to : v[now])
		if(to != fa) DFS2(to , now);
	for(auto to : v[now]){
		if(to == fa) continue;
		RREP(i , siz[now] , 0){
			RREP(j , siz[to] , 0){
				if(i + j <= siz[now]){
					dp[now][i + j] = min(dp[now][i + j] , dp[now][i] + dp[to][j]);
				}
			}
		}
	}
	REP(i , 0 , siz[now] + 1)
		dp[now][i] = min(dp[now][i] , dp[now][siz[now] - i] + 1);
	// REP(i , 0 , siz[now] + 1)
	// 	cout << dp[now][i] << " " ; cout << endl;
}
int32_t main(){
	cin >> n;
	REP(i , 1 , n){
		int q , w;
		cin >> q >> w;
		v[q].pb(w) , v[w].pb(q);
	}
	if(n == 2) cout << 1 << endl;
	else {
		int root;
		REP(i , 1 , n + 1) if(v[i].size() != 1) root = i;
		DFS1(root , 0);
		DFS2(root , 0);
		cout << dp[root][siz[root] / 2] << endl;
	}
    return 0;
}