/*input
7 4
1 1 3 3 5 3
1
2
3
5
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 300090
#define INF 0x3f3f3f3f

int pa[MAX] , siz[MAX] , big[MAX] , ans[MAX];
int n , m;
vector<int> sol , v[MAX];
void DFS(int now){
	siz[now] = 1;
	big[now] = 0;
	for(auto to : v[now]){
		DFS(to);
		siz[now] += siz[to];
		big[now] = max(big[now] , siz[to]);
	}
	sol.pb(now);
}

void solve(){
	DFS(1);
	for(auto now : sol){
		PII all = mp(0 , now);
		for(auto to : v[now]) all = max(all , mp(siz[to] , ans[to]));

		int id = all.B;
		PII val = mp(max(big[id] , siz[now] - siz[id]) , id);
		while(id != now){
			int pat = pa[val.B];
			PII tmp = mp(max(big[pat] , siz[now] - siz[pat]) , pat);
			// DB4(now , "tmp = " , tmp.A , tmp.B);
			if(tmp.A <= val.A) val = tmp;
			else break;
		}
		ans[now] = val.B;
		// DB4(now , "final = " , val.A , val.B);
		// if(now == 5) exit(0);
	}
}
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 2 , n + 1){
		cin >> pa[i];
		v[pa[i]].pb(i);
	}
	solve();
	// REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
	REP(i , 1 , m + 1){
		int in; cin >> in;
		cout << ans[in] << endl;
	}
    return 0;
}