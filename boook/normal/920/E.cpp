/*input
5 5
1 2
3 4
3 2
4 2
2 5
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
#define MAX 200900
#define INF 0x3f3f3f3f

struct N{
	int x[MAX] , siz[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i , siz[i] = 1; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){
		a = Find(a) , b = Find(b);
		if(a == b) return;
		x[a] = b , siz[b] += siz[a];
	}
	int operator[](int now){ return Find(now); }
} ds;
int n , m , use[MAX];

int32_t main(){
	IOS;
	cin >> n >> m;
	set<PII> no;
	set<int> sol;
	REP(i , 1 , m + 1){
		int a , b; cin >> a >> b;
		no.insert(mp(a , b));
		no.insert(mp(b , a));
	}
	ds.init();
	REP(i , 2 , n + 1) sol.insert(i);
	REP(i , 1 , n + 1){
		if(use[i]) continue;
		queue<int> qu;
		qu.push(i);
		while(qu.size()){
			int now = qu.front(); qu.pop();
			vector<int> de;
			for(auto to : sol){
				if(no.find(mp(now , to)) != no.end()) continue;
				else{
					ds.Union(i , to);
					qu.push(to);
					de.pb(to);
					use[to] = 1;
				}
			}
			for(auto tmp : de) sol.erase(tmp);
		}
	}
	vector<int> ans;
	REP(i , 1 , n + 1) if(ds[i] == i) ans.pb(ds.siz[i]);
	sort(ALL(ans));
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}