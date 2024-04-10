/*input
3 3 2 5
1 2 2
2 2 1
2 3 5
3 2 10
2 1 100
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
#define MAX 550
#define INF 0x3f3f3f3f

int n , m , o , k , x[MAX * MAX][2] , t[MAX * MAX];
int p[MAX][MAX];
int judge(int lim){
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) p[i][j] = 0;
	REP(i , 1 , k + 1) if(t[i] <= lim) p[x[i][0]][x[i][1]] = 1;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) p[i][j] += p[i][j - 1];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) p[i][j] += p[i - 1][j];

	// REP(i , 1 , n + 1){
	// 	REP(j , 1 , m + 1) cout << p[i][j] << " ";
	// 	cout << endl;
	// }
	REP(i , o , n + 1) REP(j , o , m + 1){
		int tmp = p[i][j] - p[i - o][j] - p[i][j - o] + p[i - o][j - o];
		if(tmp == o * o) return 1;
	}
	return 0;
}
int32_t main(){
	IOS , cin >> n >> m >> o >> k;
	REP(i , 1 , k + 1) cin >> x[i][0] >> x[i][1] >> t[i];
	// DBGG("judge(8) = " , judge(8));
	int now = -1 , ok = 0;
	RREP(i , 30 , 0){
		int to = now + (1 << i);
		if(judge(to) == 0) now = to;
		else ok = 1;
	}
	if(ok) cout << now + 1 << endl;
	else cout << -1 << endl;
    return 0;
}