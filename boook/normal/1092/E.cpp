/*input
4 2
1 2
2 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define F    first
#define S    second
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
#define MAX 2000
#define INF 0x3f3f3f3f

int n , m , u[MAX];
vector<int> v[MAX];
vector<int> line;
PII DFS(int now , int fa , int deep){
	PII ans = mp(deep , now);
	u[now] = 1;
	for(auto to : v[now]) if(to != fa)
		ans = max(ans , DFS(to , now , deep + 1));
	return ans;
} 
int DFS1(int now , int fa , int wnt){
	if(now == wnt) return line.pb(now) , 1;
	for(auto to : v[now]) if(to != fa){
		if(DFS1(to , now , wnt)){
			line.pb(now);
			return 1;			
		}
	}
	return 0;
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int big = 0 , idx = -1;
	vector<int> mid;
	REP(i , 1 , n + 1) if(u[i] == 0){
		PII tmp = DFS(i , i , 0);
		PII sec = DFS(tmp.S , tmp.S , 0);
		line.clear();
		DFS1(tmp.S , tmp.S , sec.S);
		int res = line[line.size() / 2];
		if(line.size() > big){
			big = line.size();
			idx = res;
		}
		// cout << "get line = ";
		// for(auto to : line) cout << to << " " ; cout << endl;
		mid.pb(res);
	}
	vector<PII> add;
	for(auto to : mid) if(to != idx) add.pb(idx , to) , v[to].pb(idx) , v[idx].pb(to);
	PII v1 = DFS(1 , 1 , 0);
	v1 = DFS(v1.S , v1.S , 0);
	cout << v1.F << endl;
	for(auto to : add){
		cout << to.F << " " << to.S << endl;
	}
    return 0;
}