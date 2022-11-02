#include <bits/stdc++.h>
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define MAX 400
#define PII pair<int , int>
#define mp make_pair
#define pb push_back
#define A first
#define B second
using namespace std;

int n , x[MAX] , u[MAX] , e[MAX][2];
vector<int> v[MAX];
PII DFS(int now , int fa , int deep){
	PII ans = mp(deep , now);
	for(auto i : v[now]) if(u[i] == 0){
		int to = e[i][0] ^ e[i][1] ^ now;
		if(to != fa) ans = max(ans , DFS(to , now , deep + 1));
	}
	return ans;
}
signed main(){
	cin >> n;
	REP(i , 2 , n + 1){
		cin >> e[i][0] >> e[i][1];
		v[e[i][0]].pb(i);
		v[e[i][1]].pb(i);
	}
	int ans = 0;
	REP(i , 2 , n + 1){
		u[i] = 1;
		int a = DFS(DFS(e[i][0] , 0 , 0).B , 0 , 0).A;
		int b = DFS(DFS(e[i][1] , 0 , 0).B , 0 , 0).A;
		ans = max(ans , a * b);
		u[i] = 0;
	}
	cout << ans << endl;
	return 0;
}