#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define mp make_pair
#define pb push_back
#define PII pair<int , int>
#define A first
#define B second
#define int long long
#define MAX 100900
int n , m;
vector<PII> v[MAX];
PII DFS(int now , int fa , int deep){
	PII ans = mp(deep , now);
	for(auto to : v[now]) if(to.A != fa){
		ans = max(ans , DFS(to.A , now , deep + to.B));
	}
	return ans;
}
int32_t main(){
	cin >> n;
	int ans = 0;
	REP(i , 2 , n + 1){
		int a , b , c;
		cin >> a >> b >> c;
		v[a].pb(mp(b , c));
		v[b].pb(mp(a , c));
		ans += c + c;
	}
	ans -= DFS(1 , 0 , 0).A;
	cout << ans << endl;
	return 0;
}