#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 7000
#define INF 0x3f3f3f3f

int n , val[MAX] , ans;
vector<int> v[MAX] , tmp;
void DFS(int now , int fa){
	PII ty = mp(-1 , -1);
	if(tmp.empty() || tmp.back() < val[now]) tmp.pb(val[now]);
	else {
		int k = lower_bound(ALL(tmp) , val[now]) - tmp.begin();
		ty = mp(k , tmp[k]);
		tmp[k] = val[now];
	}
	ans = max(ans , (int)tmp.size());
	for(auto to : v[now]){
		if(to != fa) DFS(to , now);
	}
	if(ty.A == -1) tmp.pop_back();
	else tmp[ty.A] = ty.B;
}
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> val[i];
	REP(i , 1 , n){
		int q , w;
		cin >> q >> w;
		v[q].pb(w);
		v[w].pb(q);
	}
	REP(i , 1 , n + 1){
		DFS(i , -1);
	}
	cout << ans << endl;
    return 0;
}