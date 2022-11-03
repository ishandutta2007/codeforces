#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define DBGG(i , j) cout << i << " " << j << endl
//------------------------------------------
#define int long long
#define INF 0x3f3f3f3f
#define MAX 300900

int n , m , ok[MAX] , siz[MAX] , ans = 0;
vector<int> v[MAX];
void DFS(int now , int fa){
	siz[now] = ok[now];
	REP(i , 0 , v[now].size()){
		int to = v[now][i];
		if(to == fa) continue;
		DFS(to , now);
		siz[now] += siz[to];
		ans += min(m + m - siz[to] , siz[to]);
	}
}
int32_t main(){
	cin.tie(0) , cout.sync_with_stdio(0);
	cin >> n >> m;
	REP(i , 1 , m + m + 1){
		int in; cin >> in;
		ok[in] = 1;
	}
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	DFS(1 , 0);
	cout << ans << endl;
	return 0;
}