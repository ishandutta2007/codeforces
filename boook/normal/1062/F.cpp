/*input
6 7
1 2
2 3
3 4
1 5
5 3
2 6
6 4
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , u[MAX];
int fr[MAX] , no[MAX] , in[MAX] , d[MAX];

vector<int> G1[MAX], G2[MAX], p;

void DFS(int now){
	if(u[now]) return ;
	u[now] = 1;
	for(auto to : G1[now]) DFS(to);
	p.pb(now);
}
void solve(){
	REP(i , 1 , n + 1) in[i] = 0;
	set<int> cc;
	for(auto now : p){
		for(auto to : G1[now]){
			if(in[to] == 0) d[now] ++ , cc.erase(to) , fr[to] = now;
			if(in[to] == 1) d[fr[to]] --;
			in[to] ++;
		}
		if(cc.size() == 1){
			if(d[*cc.begin()] == 0) no[now] += 1;
			else no[now] += 10;
		}
		else if(cc.size() > 1) no[now] += 10;
		cc.insert(now);
	}
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		G1[a].pb(b);
		G2[b].pb(a);
	}
	REP(i , 1 , n + 1) DFS(i);

	solve();

	reverse(ALL(p));
	REP(i , 1 , n + 1) G1[i] = G2[i];

	solve();

	int ans = 0;
	REP(i , 1 , n + 1) ans += no[i] <= 1;
	cout << ans << endl;
    return 0;
}