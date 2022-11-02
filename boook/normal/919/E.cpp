/*input
1 1 2 1
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , mod , k;
int ppow(int now , int v){
	if(v == 0) return 1;
	if(v % 2 == 0) return ppow(now * now % mod , v >> 1);
	if(v % 2 == 1) return ppow(now * now % mod , v >> 1) * now % mod;
}
int ni[MAX] , a[MAX] , b[MAX] , att[MAX];
int32_t main(){
	IOS;
	a[0] = 1;
	cin >> n >> m >> mod >> k;

	REP(i , 1 , mod + 0) ni[i] = ppow(i , mod - 2);
	REP(i , 1 , mod + 0) a[i] = a[i - 1] * n % mod;
	REP(i , 1 , mod + 1) b[i] = m * ni[i] % mod;
	REP(i , 1 , mod + 1) att[b[i]] = i;

	// REP(i , 1 , mod + 0) cout << a[i] << " " ; cout << endl;
	// REP(i , 1 , mod + 1) cout << b[i] << " " ; cout << endl;
	// REP(i , 1 , mod + 1) cout << b[i] << " " ; cout << endl;

	int ans = 0;
	REP(i , 1 , mod + 0){
		int now = 0 , wh = att[a[i]] , first = 0;
		if(wh <= i) first = (i - wh) * (mod - 1) + i;
		else first = (i - wh + mod) * (mod - 1) + i;
		// DBGG("first = " , first);
		RREP(j , 50 , 0){
			int to = now + (1LL << j) , ttt = max(1LL , to - 1);
			if(to != 1 && k / mod / (mod - 1) / (to - 1) == 0) continue;
			// DB4("to = " , to , "cost = " , (to - 1) * (mod - 1) * mod + first);
			if((to - 1) * (mod - 1) * mod + first <= k) now = to;
		}
		ans += now;
	}
	cout << ans << endl;
    return 0;
}

/*
5 4 6 2 3 1 5 4 6 2 3 1 5 4 6 2 3 1 5 4 6 2 3 1 5 4 6 2 3 1 5 4 6 2 3 1 5 4 6 2 3 1 
6 3 2 5 4 1 0 6 3 2 5 4 1 0 6 3 2 5 4 1 0 6 3 2 5 4 1 0 6 3 2 5 4 1 0 6 3 2 5 4 1 0 
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 
*/