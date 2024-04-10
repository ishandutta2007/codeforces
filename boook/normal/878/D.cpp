/*input
2 2 4
1 2
2 1
1 1 2
2 1 2
3 3 1
3 4 2
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
#define MAX 100090
#define INF 0x3f3f3f3f

bitset<4100> b[MAX];
int n , m , k , cmpnow , x[MAX][13] , s[MAX][13] , rk[MAX][13] , id[MAX] , pos;
int cmp(int v1 , int v2){ return x[cmpnow][v1] < x[cmpnow][v2]; }
int32_t main(){
	IOS;
	cin >> n >> m >> k , pos = m;
	REP(i , 0 , m) REP(j , 0 , n) cin >> x[j][i];

	REP(i , 0 , n){
		cmpnow = i;
		REP(j , 0 , m) s[i][j] = j;
		sort(s[i] , s[i] + m , cmp);
		REP(j , 0 , m) rk[i][s[i][j]] = j;
	}
	
	// REP(i , 0 , n) {REP(j , 0 , m) cout << rk[i][j] << " "; cout << endl;}
	// cout << endl;
	// REP(i , 0 , n) {REP(j , 0 , m) cout << s[i][j] << " "; cout << endl;}

	REP(i , 0 , m) REP(j , 0 , (1 << m)) if(j & (1 << i)) b[i].set(j);
	// cout << "********" << endl;
	// REP(i , 0 , m) cout << b[i] << endl;
	// cout << "********" << endl;
	REP(T , 0 , k){
		int ty , v1 , v2;
		cin >> ty >> v1 >> v2 , -- v1 , -- v2;
		if(ty == 1) b[pos ++] = b[v1] | b[v2];// , cout << b[pos - 1] << endl;
		if(ty == 2) b[pos ++] = b[v1] & b[v2];// , cout << b[pos - 1] << endl;
		if(ty == 3){
			int ans = m - 1 , pat = 0;
			for( ; ; ans --){
				pat |= (1 << s[v2][ans]);
				if(ans == 0 || b[v1][pat] == 1) break;
			}
			// DB4("pat = " , pat , s[v2][ans] , ans);
			cout << x[v2][s[v2][ans]] << endl;
		}
	}
    return 0;
}