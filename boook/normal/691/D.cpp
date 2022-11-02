/*input
9 6
1 2 3 4 5 6 7 8 9
1 4
4 7
2 5
5 8
3 6
6 9
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
#define MAX 1000900
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; } 
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ return x[Find(a)] = Find(b) , void(); }
	int operator[](int now){ return Find(x[now]); }
} ds;
int n , m , x[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS , cin >> n >> m;
	ds.init();
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		ds.Union(a , b);
	}
	REP(i , 1 , n + 1) v[ds[i]].pb(x[i]);
	REP(i , 1 , n + 1) sort(ALL(v[i]));
	REP(i , 1 , n + 1){
		cout << v[ds[i]].back() << " ";
		v[ds[i]].pop_back();
	}
	cout << endl;
    return 0;
}