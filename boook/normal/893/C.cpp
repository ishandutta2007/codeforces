/*input
10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10
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
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int a[MAX];
struct djs{
	int x[MAX] , val[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i , val[i] = a[i]; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){
		a = Find(a) , b = Find(b);
		x[a] = b;
		val[b] = min(val[b] , val[a]);
	}
	int operator[](int now){ return Find(x[now]); }
}ds;
int n , m;
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	ds.init();
	REP(i , 1 , m + 1){
		int q , w;
		cin >> q >> w;
		ds.Union(q , w);
	}
	int res = 0;
	REP(i , 1 , n + 1){
		if(ds[i] == i){
			res += ds.val[i];
		}
	}
	cout << res << endl;
    return 0;
}