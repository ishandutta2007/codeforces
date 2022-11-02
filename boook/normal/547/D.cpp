/*input
3
1 1
1 2
2 1
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , sol[MAX] , col[MAX];
PII x[MAX];
vector<int> v[MAX];
int cmp1(int a , int b){
	if(x[a].A == x[b].A) return x[a].B < x[b].B;
	if(x[a].A != x[b].A) return x[a].A < x[b].A;
}
int cmp2(int a , int b){
	if(x[a].B == x[b].B) return x[a].A < x[b].A;
	if(x[a].B != x[b].B) return x[a].B < x[b].B;
}
void DFS(int now , int ty){
	col[now] = ty;
	for(auto to : v[now]){
		if(col[to] == 0) DFS(to , 3 - ty);
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
	REP(i , 1 , n + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + n , cmp1);
	REP(i , 2 , n + 1){
		int pre = sol[i - 1] , now = sol[i];
		if(x[pre].A == x[now].A) v[pre].pb(now) , v[now].pb(pre) , i ++;
	}
	sort(sol + 1 , sol + 1 + n , cmp2);
	REP(i , 2 , n + 1){
		int pre = sol[i - 1] , now = sol[i];
		if(x[pre].B == x[now].B) v[pre].pb(now) , v[now].pb(pre) , i ++;
	}
	REP(i , 1 , n + 1) if(col[i] == 0) DFS(i , 1);
	REP(i , 1 , n + 1){
		if(col[i] == 1) cout << "b" ;
		if(col[i] == 2) cout << "r" ;
	}
	cout << endl;
    return 0;
}