/*input
5
1 2
1 3
2 4
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
#define int long long
#define MAX 300000
#define INF 0x3f3f3f3f

vector<int> v[MAX];
int pa[MAX] , use[MAX];
vector<int> fk;
void DFS3(int now , int fa){
	for(auto to : v[now]){
		if(to == fa) continue;
		DFS3(to , now);
	}
	fk.pb(now);
}
int DFS2(int now , int fa , int deep , int dep[MAX]){
	dep[now] = deep;
	pa[now] = fa;
	for(auto to : v[now]){
		if(to == fa) continue;
		DFS2(to , now , deep + 1 , dep);
	}
}
int n , d1[MAX] , d2[MAX];
PII DFS1(int now , int fa , int deep){
	PII ans = mp(deep , now);
	for(auto to : v[now]){
		if(to == fa) continue;
		ans = max(ans , DFS1(to , now , deep + 1));
	}
	return ans;
}
vector<PII> ans;
int32_t main(){
	cin >> n;
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int fr = DFS1( 1 , 0 , 0).B;
	int ba = DFS1(fr , 0 , 0).B;
	// DB4("fr = " , fr , "ba = " , ba);
	DFS2(ba , 0 , 0 , d2);
	DFS2(fr , 0 , 0 , d1);
	DFS3(fr , 0);
	int now = ba;
	vector<int> sol;
	while(1){
		sol.pb(now);
		use[now] = 1;
		if(now == fr) break;
		else now = pa[now];
	}
	int dis = 0;
	for(auto i : fk){
		if(use[i]) continue;
		if(d1[i] > d2[i]) ans.pb(fr , i) , dis += d1[i];
		else              ans.pb(ba , i) , dis += d2[i];
	}
	for(auto to : sol) if(to != fr) ans.pb(fr , to) , dis += d1[to];

	cout << dis << endl;
	for(auto to : ans){
		cout << to.A << " " << to.B << " " << to.B << endl;
	}
    return 0;
}