/*input
6 8
....*...
...**...
..*****.
...**...
....*...
........
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
#define MAX 1010
#define INF 0x3f3f3f3f

string s[MAX];
int n , m , ans[MAX][MAX] , use[MAX][MAX];
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
int x[MAX][MAX][4] , u[MAX][MAX][4];
int p[MAX][MAX][4] , v[MAX][MAX][4];
inline int in(int i , int j){
	return 0 <= i && i < n && 0 <= j && j < m && s[i][j] == '*';
}
int DP(int i , int j , int k){
	if(u[i][j][k]) return x[i][j][k];
	u[i][j][k] = 1;
	if(in(i , j) == 0) return x[i][j][k] = 0;
	if(in(i , j) == 1) return x[i][j][k] = 1 + DP(i + X[k] , j + Y[k] , k);
}
int PP(int i , int j , int k){
	if(v[i][j][k]) return p[i][j][k];
	if(0 <= i && i < n && 0 <= j && j < m);
	else return 0;
	v[i][j][k] = 1;
	p[i][j][k] = max(p[i][j][k] , PP(i - X[k] , j - Y[k] , k) - 1);
	return p[i][j][k];
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];

	REP(i , 0 , n) REP(j , 0 , m) REP(k , 0 , 4) DP(i , j , k);

	REP(i , 0 , n) REP(j , 0 , m){
		int sml = INF;
		REP(k , 0 , 4) sml = min(sml , x[i][j][k]);

		REP(k , 0 , 4) if(sml > 1) p[i][j][k] = ans[i][j] = sml;
	}

	REP(i , 0 , n) REP(j , 0 , m) REP(k , 0 , 4) PP(i , j , k);
	REP(i , 0 , n) REP(j , 0 , m) REP(k , 0 , 4) if(p[i][j][k]) use[i][j] = 1;

	REP(i , 0 , n) REP(j , 0 , m) if(use[i][j] == 0 && in(i , j))
		return cout << -1 << endl , 0;

	int cnt = 0;
	REP(i , 0 , n) REP(j , 0 , m) if(ans[i][j] > 1) cnt ++;
	cout << cnt << endl;
	REP(i , 0 , n) REP(j , 0 , m) if(ans[i][j] > 1) cout << i + 1 << " " << j + 1 << " " << ans[i][j] - 1 << endl;

    return 0;
}