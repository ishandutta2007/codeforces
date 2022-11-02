/*input
5 4
1 2 3 4 5
1 2 8
1 3 10
1 4 7
1 5 15
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
#define int long long
#define MAX 200009
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int a){ return Find(a); }
} ds;
int n , m , x[MAX];
vector<pair<int , PII>> e;
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	PII sml = mp(x[1] , 1);
	REP(i , 1 , n + 1) sml = min(sml , mp(x[i] , i));
	REP(i , 1 , n + 1) if(i != sml.S) e.pb(mp(x[i] + sml.F , mp(i , sml.S)));
	REP(i , 1 , m + 1){
		int a , b , c;
		cin >> a >> b >> c;
		e.pb(mp(c , mp(a , b)));
	}
	sort(ALL(e));
	ds.init();
	long long ans = 0;
	for(auto to : e){
		if(ds[to.S.F] != ds[to.S.S]) ans += to.F , ds.Union(to.S.F , to.S.S);
	}
	cout << ans << endl;
    return 0;
}