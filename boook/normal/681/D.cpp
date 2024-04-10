/*input
4 2
1 2
3 4
1 2 3 3
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , root[MAX] , can[MAX] , dep[MAX];
vector<int> v[MAX] , ans , check;
set<PII> cc[MAX];
int DFS(int now , int deep){
	dep[now] = deep;
	int sml = dep[x[now]];
	for(auto to : v[now]) sml = min(sml , DFS(to , deep + 1));

	// DBGG(sml , now);
	if(can[now] && sml < deep){
		cout << -1 << endl;
		exit(0);
	}

	if(can[now]) cc[now].insert(mp(sml , now));
	for(auto to : v[now]){
		if(cc[to].size() > cc[now].size()) swap(cc[now] , cc[to]);
		else for(auto val : cc[to]) cc[now].insert(val);
	}

	while(cc[now].size() && (*cc[now].begin()).A >= deep){
		ans.pb((*cc[now].begin()).B);
		// DBGG("push = " , (*cc[now].begin()).B);
		cc[now].erase(cc[now].begin());
	}
	return sml;
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) root[i] = 1;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b) , root[b] = 0;
	}
	REP(i , 1 , n + 1) cin >> x[i] , can[x[i]] = 1;

	REP(i , 1 , n + 1) if(root[i] == 1) DFS(i , 1);
	for(auto to : ans) if(can[to] == 1) check.pb(to);
	cout << check.size() << endl;
	for(auto to : check) cout << to << endl;
    return 0;
}