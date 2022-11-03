/*input
4 3
1 3 2 4
1 2
2 3
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , a[MAX];
double x[MAX][MAX] , p[MAX][MAX];
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i] , x[i][a[i]] = 1;
	REP(times , 1 , m + 1){
		int q , w; cin >> q >> w;
		REP(i , 1 , n + 1) x[q][i] = x[w][i] = (x[q][i] + x[w][i]) / 2;
	}
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) p[i][j] = x[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) x[i][j] += x[i][j - 1];
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) x[i][j] += x[i - 1][j];
	double ans = 0;
	REP(i , 1 , n + 0) REP(j , 1 , n + 1){
		double v1 = x[n][j - 1] - x[i][j - 1];
		double v2 = x[n][j] - x[n][j - 1] - x[i][j] + x[i][j - 1];
		ans += p[i][j] * v1 + p[i][j] * v2 / 2;
	}
	printf("%.11f\n", ans);
    return 0;
}