/*input
5 7
1 2 2
1 3 2
2 3 1
2 4 1
3 4 1
3 5 2
4 5 2
4
2 3 4
3 3 4 5
2 1 7
2 1 2
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
#define endl "\n"
///------------------------------------------------------------
#define MAX 500900
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(now); }
} ds;
int n , m , k , ok[MAX] , e[MAX][2] , w[MAX] , qq[MAX];
PII help[MAX];
vector<int> sol[MAX];
int ddd[MAX];
int Find(int now){ return ddd[now] == now ? now : ddd[now] = Find(ddd[now]); }
void Union(int a , int b){ ddd[Find(a)] = Find(b); }
int32_t main(){
	ds.init();
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1) cin >> e[i][0] >> e[i][1] >> w[i];
	REP(i , 1 , m + 1) sol[w[i]].pb(i);

	REP(tt , 1 , MAX){
		for(auto to : sol[tt]){
			int a = ds[e[to][0]];
			int b = ds[e[to][1]];
			if(a != b) ok[to] = 1;
			help[to] = mp(max(a , b) , min(a , b));
		}
		for(auto to : sol[tt]){
			if(ds[e[to][0]] != ds[e[to][1]]) ds.Union(e[to][0] , e[to][1]);
		}
	}
	cin >> k;
	REP(tt , 1 , k + 1){
		int nn , tok = 1;
		cin >> nn;
		set<PII> cc;
		REP(i , 1 , nn + 1){
			cin >> qq[i];
			ddd[e[qq[i]][0]] = e[qq[i]][0];
			ddd[e[qq[i]][1]] = e[qq[i]][1];
			if(ok[qq[i]] == 0) tok = 0;
		}
		REP(i , 1 , nn + 1){
			int a = e[qq[i]][0];
			int b = e[qq[i]][1];
			cc.insert(help[qq[i]]);
			if(Find(a) != Find(b)){
				Union(a , b);
			}
			else {
				tok = 0;
				break;
			}
		}
		if(cc.size() != nn) tok = 0;
		if(tok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    return 0;
}