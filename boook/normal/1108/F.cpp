/*input
5 6
1 2 2
2 3 1
4 5 3
2 4 2
1 4 2
1 5 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200009
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator [](int now){ return Find(now); }
} fr , se;
int n , m , e[MAX][3];
map<int , vector<int>> cc;
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1) cin >> e[i][0] >> e[i][1] >> e[i][2];
	REP(i , 1 , m + 1) cc[e[i][2]].pb(i);
	int ans = 0;
	fr.init() , se.init();
	for(auto to : cc){
		for(auto idx : to.S){
			if(fr[e[idx][0]] == fr[e[idx][1]]) continue;
			else if(se[e[idx][0]] == se[e[idx][1]]) ans ++;
			else se.Union(e[idx][0] , e[idx][1]);
		}
		for(auto idx : to.S){
			if(fr[e[idx][0]] == fr[e[idx][1]]) continue;
			else fr.Union(e[idx][0] , e[idx][1]);
		}
	}
	cout << ans << endl;
    return 0;
}