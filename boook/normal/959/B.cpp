/*input
5 4 4
i loser am the second
100 20 1 5 10
1 1
1 3
2 2 5
1 4
i am the second
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
#define MAX 100900
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(now); }
} ds;
int n , m , k , v[MAX] , sml[MAX];
string s[MAX];
map<string , int> cc; 
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> s[i] , cc[s[i]] = i;
	REP(i , 1 , n + 1) cin >> v[i];
	REP(i , 1 , n + 1) sml[i] = v[i];
	// REP(i , 1 , n + 1) cout << sml[i] << " ";  cout << endl;
	ds.init();
	REP(i , 1 , m + 1){
		int nn , in , base;
		cin >> nn >> base;
		REP(j , 2 , nn + 1){
			cin >> in;
			ds.Union(base , in);
		}
	}
	REP(i , 1 , n + 1) sml[ds[i]] = min(sml[ds[i]] , v[i]);
	int ans = 0;
	REP(i , 1 , k + 1){
		string now;
		cin >> now;
		ans += sml[ds[cc[now]]];
	}
	cout << ans << endl;
    return 0;
}