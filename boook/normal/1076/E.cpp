/*input
5
2 3
2 1
5 4
3 4
5
2 0 4
3 10 1
1 2 3
2 3 10
1 1 7
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
const int MAX = 300900;
const int INF = 0x3f3f3f3f;

int bit[MAX];

int n , m , ans[MAX];
vector<int> v[MAX] , d[MAX] , s[MAX];
void DFS(int now , int fa , int deep , int preans){
	ans[now] = preans - bit[deep];
	REP(i , 0 , d[now].size()){
		d[now][i] = min(d[now][i] , n + 1);
		ans[now] += s[now][i];
	}
	
	REP(i , 0 , d[now].size()) bit[ deep + d[now][i] + 1 ] += s[now][i];
	for(auto to : v[now]) if(to != fa)
		DFS(to , now , deep + 1 , ans[now]);
	REP(i , 0 , d[now].size()) bit[ deep + d[now][i] + 1 ] -= s[now][i];
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
	cin >> m;
	REP(i , 1 , m + 1){
		int a , b , c;
		cin >> a >> b >> c;
		d[a].pb(b);
		s[a].pb(c);
	}
	DFS(1 , 1 , 1 , 0);
	REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}