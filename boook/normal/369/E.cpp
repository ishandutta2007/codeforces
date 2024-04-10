/*input
3 3
1 3
4 5
6 7
3 1 4 7
2 4 5
1 8
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 2000000
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
	// DBGG("now update" , from);
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int res = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		res += bit[i];
	return res;
}
int query(int l , int r){
	// DB4("now query = from" , l , "to" , r);
	return query(r) - query(l - 1);
}
int n , m , ty[MAX] , l[MAX] , r[MAX] , sol[MAX] , tto[MAX] , ans[MAX] , po = 1;
int cmp(int a , int b){
	if(l[a] != l[b]) return l[a] < l[b];
	return a < b;
}
int32_t main(){

	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1){
		ty[po] = 0;
		cin >> l[po] >> r[po];
		po ++;
	}
	REP(i , 1 , m + 1){
		int nn; cin >> nn;
		REP(j , 1 , nn + 1) cin >> sol[j];
		sol[nn + 1] = 1000090;
		REP(j , 1 , nn + 1){
			ty[po] = 1;
			l[po] = sol[j];
			r[po] = sol[j + 1] - 1;
			tto[po] = i;
			po ++;
		}
	}
	REP(i , 1 , po) sol[i] = i;

	sort(sol + 1 , sol + po , cmp);
	REP(tt , 1 , po){
		int i = sol[tt];
		if(ty[i] == 0) update(r[i] , 1);
		if(ty[i] == 1){
			ans[tto[i]] += query(l[i] , r[i]);
		}
	}
	REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}