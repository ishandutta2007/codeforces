/*input
6
10 10 50 10 50 50
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
#define MAX 209000
#define INF 0x3f3f3f3f

struct{
	int x[MAX] , l[MAX] , r[MAX] , siz[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = l[i] = r[i] = i , siz[i] = 1; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){
		a = Find(a) , b = Find(b);
		x[a] = b;
		l[b] = min(l[a] , l[b]);
		r[b] = max(r[a] , r[b]);
		siz[b] += siz[a];
	}
	int operator[](int now){ return Find(now); }
} ds;
int n , x[MAX];
int32_t main(){
	ds.init();
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1) if(x[i] == x[i - 1]) ds.Union(i , i - 1);
	set<PII> cc;
	REP(i , 1 , n + 1) if(ds[i] == i) cc.insert(mp(ds.siz[i] , -i));
	int ans = 0;

	while(cc.size()){
		PII tmp = *prev(cc.end()); ans ++ , cc.erase(prev(cc.end()));
		// DBGG(tmp.A , tmp.B);
		int id = ds[-tmp.B]; ds.siz[id] = 0;
		int lid = ds[ds.l[id] - 1];
		int rid = ds[ds.r[id] + 1];
		if(x[lid] == x[rid] && lid >= 1 && rid <= n){
			cc.erase(mp(ds.siz[lid] , -lid));
			cc.erase(mp(ds.siz[rid] , -rid));
			ds.Union(rid , lid);
			cc.insert(mp(ds.siz[lid] , -lid));
		}
		ds.Union(id , lid);
		// if(ans > 10) break;
	}
	cout << ans << endl;
    return 0;
}