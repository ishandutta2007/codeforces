/*input
6 10
##########
#K#..#####
#.#..##.##
#..L.#...#
###D###A.#
##########
4
N 2
S 1
E 1
W 2
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

int n , m , k , g[100900] , v[MAX][MAX];
int u[MAX][MAX] , l[MAX][MAX] , r[MAX][MAX] , d[MAX][MAX];
string s[MAX] , x[100900];
void solveinit(){
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) v[i][j] = s[i - 1][j - 1] != '#';

	REP(i , 1 , n + 1) REP(j , 1 , m + 1) u[i][j] = v[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) u[i][j] = (u[i - 1][j] + 1) * u[i][j];

	REP(i , 1 , n + 1) REP(j , 1 , m + 1) l[i][j] = v[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) l[i][j] = (l[i][j - 1] + 1) * l[i][j];

	RREP(i , n , 1) RREP(j , m , 1) r[i][j] = v[i][j];
	RREP(i , n , 1) RREP(j , m , 1) r[i][j] = (r[i][j + 1] + 1) * r[i][j];

	RREP(i , n , 1) RREP(j , m , 1) d[i][j] = v[i][j];
	RREP(i , n , 1) RREP(j , m , 1) d[i][j] = (d[i + 1][j] + 1) * d[i][j];
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	cin >> k;
	REP(i , 0 , k) cin >> x[i] >> g[i];
	solveinit();
	vector<char> ans;
	REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] != '#' && s[i][j] != '.'){
		int xx = i + 1 , yy = j + 1 , ok = 1;
		REP(ii , 0 , k){
			if(x[ii] == "N"){
				if(u[xx][yy] - 1 < g[ii]) ok = 0;
				else xx -= g[ii];
			}
			if(x[ii] == "S"){
				if(d[xx][yy] - 1 < g[ii]) ok = 0;
				else xx += g[ii];
			}
			if(x[ii] == "W"){
				if(l[xx][yy] - 1 < g[ii]) ok = 0;
				else yy -= g[ii];
			}
			if(x[ii] == "E"){
				if(r[xx][yy] - 1 < g[ii]) ok = 0;
				else yy += g[ii];
			}
			if(ok == 0) break;
		}
		if(ok) ans.pb(s[i][j]);
	}
	if(ans.size() == 0) cout << "no solution" << endl;
	else {
		sort(ALL(ans));
		for(auto to : ans) cout << to ; cout << endl;
	}
    return 0;
}