#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define PII pair<int , int>
#define pb push_back
#define DBGG(i , j) cout << i << " " << j << endl
#define A first
#define B second
#define mp make_pair
#define MAX 200900

int n , x[MAX];
vector<int> v[MAX];
PII DFS(int now , int fa , int deep){
	PII ans = mp(deep , now);
	for(auto to : v[now]) if(to != fa){
		if(x[now] == x[to]) ans = max(ans , DFS(to , now , deep));
		if(x[now] != x[to]) ans = max(ans , DFS(to , now , deep + 1));
	}
	return ans;
}
signed main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int ans = DFS(DFS(1 , 0 , 0).B , 0 , 0).A + 1;
	cout << ans / 2 << endl;
	return 0;
}