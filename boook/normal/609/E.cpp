/*input

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
#define int int_fast64_t
#define MAX 200900
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX] , v[MAX] , siz[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i , siz[i] = 1; }
	int Find(int now){ return now == x[now] ? now : Find(x[now]); }
	void Union(int a , int b , int val){
		a = Find(a) , b = Find(b);
		if(siz[a] > siz[b]) swap(a , b);
		siz[b] += siz[a] , x[a] = b , v[a] = val;
	}
	int operator[](int now){ return Find(now); }
}ds;
int n , m , x[MAX][2] , v[MAX] , sol[MAX];
int cmp(int a , int b){ return v[a] < v[b]; }
int query(int a , int b){
	int big = 0;
	while(a != b){
		if(ds.siz[a] > ds.siz[b]) swap(a , b);
		big = max(big , ds.v[a]);
		a = ds.x[a];
	}
	return big;
}
int32_t main(){
	IOS;
	ds.init();
	cin >> n >> m;
	REP(i , 0 , m) cin >> x[i][0] >> x[i][1] >> v[i];
	REP(i , 0 , m) sol[i] = i;
	sort(sol , sol + m , cmp);

	int sml = 0;
	REP(id , 0 , m){
		int i = sol[id];
		if(ds[x[i][0]] != ds[x[i][1]]){
			sml += v[i];
			ds.Union(x[i][0] , x[i][1] , v[i]);
		}
	}
	REP(i , 0 , m){
		int tmp = query(x[i][0] , x[i][1]);
		cout << sml + v[i] - tmp << endl;
	}
    return 0;
}