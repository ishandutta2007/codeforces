#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define PII pair<int , int>
#define A first
#define B second
#define mp make_pair
#define pb emplace_back
#define MAX 1000900
#define endl "\n"
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
int in[MAX] , out[MAX] , sp[MAX][22] , dep[MAX] , po = 0;
int n , x , node = 4;
vector<int> v[MAX];
inline void DFS(int now , int deep){
	 in[now] = ++po;
	dep[now] = deep;
	for(auto to : v[now]) DFS(to , deep + 1) , sp[to][0] = now;
	out[now] = ++po;
}
inline int fa(int a , int b){
	return in[a] <= in[b] && out[b] <= out[a];
}
inline int lca(int a , int b){
	if(fa(a , b)) return a;
	RREP(i , 20 , 0) if(fa(sp[a][i] , b) == 0) a = sp[a][i];
	return sp[a][0];
}
inline int getdis(int a , int b){
	return dep[a] + dep[b] - dep[lca(a , b)] * 2;
}
int main(){
	IOS;
	cin >> n;
	v[1].pb(2) , v[1].pb(3) , v[1].pb(4);
	REP(i , 1 , n + 1){
		cin >> x;
		v[x].pb(++node);
		v[x].pb(++node);
	}
	DFS(1 , 1) , out[0] = ++po;
	REP(j , 1 , 21) REP(i , 1 , node + 1)
		sp[i][j] = sp[sp[i][j - 1]][j - 1];

	PII dot = mp(2 , 4) , tmp;
	int ans = 2 , solve = 4;
	REP(i , 1 , n + 1){
		solve ++;
		tmp = max(mp(getdis(dot.A , solve) , dot.A) , mp(getdis(dot.B , solve) , dot.B));
		if(tmp.A > ans) ans = tmp.A , dot = mp(tmp.B , solve);
		solve ++;
		cout << ans << endl;
	}
	return 0;
}