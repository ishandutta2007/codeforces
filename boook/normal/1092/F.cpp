/*input
1
1337
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

int n , x[MAX] , all;
vector<int> v[MAX];
int sum[MAX] , pre[MAX] , siz[MAX];
void DFS1(int now , int fa){
	siz[now] = x[now];
	sum[now] = 0;
	for(auto to : v[now]) if(to != fa){
		DFS1(to , now);
		siz[now] += siz[to];
		sum[now] += sum[to] + siz[to];
	}
}
void DFS2(int now , int fa){
	int tot = pre[now] + sum[now];
	for(auto to : v[now]) if(to != fa){
		int tmp = tot - (sum[to] + siz[to]);
		pre[to] = tmp + (all - siz[to]);
		DFS2(to , now);
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i] , all += x[i];
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	DFS1(1 , 1);
	DFS2(1 , 1);
	int ans = 0;
	// REP(i , 1 , n + 1) cout << sum[i] << " "; cout << endl;
	REP(i , 1 , n + 1) ans = max(ans , sum[i] + pre[i]);
	cout << ans << endl;
    return 0;
}