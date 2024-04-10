/*input
4
1 2
3 2
4 2
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
#define MAX 100800
#define INF 0x3f3f3f3f

int n , ans[MAX] , use[MAX] , siz[MAX];
vector<int> v[MAX];
priority_queue<int> pq;
PII DFS(int now , int fa , int deep){
	PII res = mp(deep , now);
	for(auto to : v[now])
		if(to != fa) res = max(res , DFS(to , now , deep + 1));
	return res;
}
int DFS2(int now , int fa , int get){
	if(now == get) use[now] = 1;
	else {
		for(auto to : v[now]) if(to != fa){
			if(DFS2(to , now , get)) return use[now] = 1 , 1;
		}
		return 0;
	}
}
void DFS3(int now , int fa){
	// DB4("now = " , now , fa , "");
	siz[now] = 1;
	int big = 0;
	for(auto to : v[now]) if(to != fa) DFS3(to , now);
	for(auto to : v[now]) if(to != fa) big = max(big , siz[to]);
	siz[now] += big;
	for(auto to : v[now]) if(to != fa){
		if(siz[to] == big) big = -1;
		else pq.push(siz[to]);
	}
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
	int a = DFS(1 , 0 , 1).B;
	PII tmp = DFS(a , 0 , 1);
	int b = tmp.B;

	ans[1] = 1 , ans[2] = tmp.A;
	DFS2(a , 0 , b);

	// REP(i , 1 , n + 1) cout << use[i] << " "; cout << endl;
	REP(i , 1 , n + 1) if(use[i]) for(auto to : v[i]) if(use[to] == 0){
		DFS3(to , i);
		pq.push(siz[to]);
	}

	int pos = 3;
	while(pq.size()){
		int now = pq.top(); pq.pop();
		ans[pos] = ans[pos - 1] + now , pos ++;
	}
	while(pos <= n) ans[pos] = ans[pos - 1] , pos ++;
	REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}