/*input
5 4
1 2
2 3
2 4
4 5
2 1
2 5
1 2
2 5
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m;
int siz[MAX] , use[MAX] , sml[MAX];
vector<int> v[MAX] , ddis[MAX] , root[MAX];
PII FindCenter(int now , int fa , int all){
	PII ans = mp(INF , now);
	siz[now] = 1;
	int big = 0;
	for(auto to : v[now]){
		if(use[to] || to == fa) continue;
		ans = min(ans , FindCenter(to , now , all));
		siz[now] += siz[to];
		big = max(big , siz[to]);
	}
	big = max(big , all - siz[now]);
	ans = min(ans , mp(big , now));
	return ans;
}
void GetDis(int now , int fa , int deep , int from){
	root[now].pb(from);
	ddis[now].pb(deep);
	for(auto to : v[now]){
		if(use[to] || to == fa) continue;
		GetDis(to , now , deep + 1 , from);
	}
}
void solveinit(int now , int all){
	now = FindCenter(now , now , all).B;
	now = FindCenter(now , now , all).B;
	use[now] = 1;
	for(auto to : v[now]) if(use[to] == 0) solveinit(to , siz[to]);
	GetDis(now , now , 0 , now);
	use[now] = 0;
}
void modify(int now){
	REP(i , 0 , root[now].size())
		sml[root[now][i]] = min(sml[root[now][i]] , ddis[now][i]);
}
int query(int now){
	int ans = INF;
	REP(i , 0 , root[now].size())
		ans = min(ans , sml[root[now][i]] + ddis[now][i]);
	return ans;
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	REP(i , 1 , n + 1) sml[i] = INF;
	solveinit(1 , n);
	modify(1);
	REP(i , 1 , m + 1){
		int ty , v;
		cin >> ty >> v;
		if(ty == 1) modify(v);
		if(ty == 2) cout << query(v) << endl;
	}
    return 0;
}