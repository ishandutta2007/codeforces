/*input
5
0 0 10 8
1 2 6 7
2 3 5 6
3 4 4 5
8 1 9 2
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
#define MAX 200000
#define INF 0x3f3f3f3f

struct N{
	int l , r , d , u;
} x[MAX] , fr[MAX] , ba[MAX];
int n;
N pull(N a , N b){
	a.l = max(a.l , b.l);
	a.r = min(a.r , b.r);
	a.d = max(a.d , b.d);
	a.u = min(a.u , b.u);
	return a;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i].d >> x[i].l >> x[i].u  >> x[i].r;
	fr[0 + 0] = N{-INF , INF , -INF , INF};
	ba[n + 1] = N{-INF , INF , -INF , INF};
	REP(i , 1 , n + 1) fr[i] = pull(fr[i - 1] , x[i]);
	RREP(i , n , 1)    ba[i] = pull(ba[i + 1] , x[i]);
	REP(i , 1 , n + 1){
		N now = pull(fr[i - 1] , ba[i + 1]);
		if(now.l <= now.r && now.d <= now.u){
			cout << now.d << " " << now.l << " " << endl;
			return 0;
		}
	}
    return 0;
}