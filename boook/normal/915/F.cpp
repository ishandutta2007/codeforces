/*input
4
2 2 3 1
1 2
1 3
1 4
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX] , siz[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i , siz[i] = 1; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ 
		a = Find(a) , b = Find(b);
		x[a] = b , siz[b] += siz[a];
	}
	int operator[](int now){ return siz[Find(now)]; }
} ds;
int n , x[MAX] , sol[MAX] , use[MAX];
vector<int> v[MAX];
int cmp(int a , int b){ return x[a] < x[b]; }
int solve(){
	ds.init();
	REP(i , 1 , n + 1) sol[i] = i , use[i] = 0;

	int val = 0;
	sort(sol + 1 , sol + 1 + n , cmp);
	REP(idx , 1 , n + 1){ int i = sol[idx];
		use[i] = 1;
		for(auto to : v[i]){
			if(ds.Find(i) != ds.Find(to) && use[to]){
				val += ds[i] * ds[to] * x[i];
				ds.Union(i , to);
			}
		}
	}
	return val;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int v1 = solve();
	REP(i , 1 , n + 1) x[i] = -x[i];
	int v2 = solve();
	cout << v1 + v2 << endl;
    return 0;
}