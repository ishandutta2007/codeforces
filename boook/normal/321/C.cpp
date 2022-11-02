#include <bits/stdc++.h>
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define MAX 100900
#define INF 0x3f3f3f3f
#define PII pair<int , int>
#define mp make_pair
#define pb push_back
#define DBGG(i , j) cout << i << " " << j << endl
#define A first
#define B second
using namespace std;

int n , use[MAX] , ans[MAX] , siz[MAX];
vector<int> v[MAX];
PII FindCenter(int now , int fa , int all){
	PII ans = mp(INF , now);
	int big = 0;
	siz[now] = 1;
	for(auto to : v[now]) if(use[to] == 0 && to != fa){
		ans = min(ans , FindCenter(to , now , all));
		siz[now] += siz[to];
		big = max(big , siz[to]);
	}
	big = max(big , all - siz[now]);
	ans = min(ans , mp(big , now));
	return ans;
}
void solve(int now , int all , int pre){
	now = FindCenter(now , now , all).B;
	ans[now] = pre;
	use[now] = 1;
	for(auto to : v[now]) if(use[to] == 0) solve(to , siz[to] , pre + 1);
	use[now] = 0;
}
signed main(){
	cin >> n;
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	solve(1 , n , 0);
	REP(i , 1 , n + 1) cout << char(ans[i] + 'A') << " ";
	cout << endl;
	return 0;
}