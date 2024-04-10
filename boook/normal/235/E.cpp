/*input
10 10 10
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , m , k , u[MAX] , gcd[MAX][MAX];

int32_t main(){
	u[1] = 1;
	REP(i , 1 , MAX) for(int j = i + i ; j < MAX ; j += i) u[j] -= u[i];
	REP(i , 1 , MAX) REP(j , i , MAX){
		if((i & 1) == 0 && (j & 1) == 0) gcd[i][j] = gcd[j][i] = 2;
		else if(i % 3 == 0 && j % 3 == 0) gcd[i][j] = gcd[j][i] = 2;
		else gcd[i][j] = gcd[j][i] = __gcd(i , j);
	}
	IOS;
	cin >> n >> m >> k;
	if(n > m) swap(n , m);
	int ans = 0;
	REP(c , 1 , k + 1){
		int res = 0;
		REP(d , 1 , n + 1){
			if(u[d] == 0) continue;
			int v1 = 0 , v2 = 0;
			for(int i = d ; i <= n ; i += d) if(gcd[i][c] == 1) v1 += n / i;
			for(int i = d ; i <= m ; i += d) if(gcd[i][c] == 1) v2 += m / i;
			res += u[d] * v1 * v2;
		}
		ans += res * (k / c);
	}
	unsigned int tmp = ans;
	cout << (tmp & ((1 << 30) - 1)) << endl;
    return 0;
}