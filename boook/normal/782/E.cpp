/*input
5 4 2
1 2
1 3
1 4
1 5
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
#define MAX 300000
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(x[now]); }
} ds;
int n , m , k , lim;
vector<int> ans , v[MAX];
void DFS(int now , int fa){
	ans.pb(now);
	for(auto to : v[now]){
		if(to == fa) continue;
		DFS(to , now);
	}
	if(fa) ans.pb(fa);
}
int32_t main(){
	ds.init();
	cin >> n >> m >> k;
	lim = (n + n) % k ? (n + n) / k + 1 : (n + n) / k;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		if(ds[a] != ds[b]){
			ds.Union(a , b);
			v[a].pb(b) , v[b].pb(a);
		}
	}
	DFS(1 , 0);
	int now = 0;
	REP(i , 1 , k + 1){
		if(now == ans.size()) now = 0;
		int to = min((int)ans.size() , now + lim);
		cout << to - now;
		REP(i , now , to) cout << " " << ans[i] ;
		cout << endl;
		now = to;
	}
    return 0;
}