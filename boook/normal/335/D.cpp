/*input
4
0 0 1 9
1 0 9 1
1 8 9 9
8 1 9 8
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
#define MAXN 100900
#define MAX  3030
#define INF 0x3f3f3f3f

int n , l[MAX][MAX] , r[MAX][MAX] , u[MAX][MAX] , d[MAX][MAX] , c[MAX][MAX];
int query(int x , int xx , int y , int yy){
	return c[xx + 1][yy + 1] - c[xx + 1][y] - c[x][yy + 1] + c[x][y];
}
int x[MAXN] , xx[MAXN] , y[MAXN] , yy[MAXN];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i] >> y[i] >> xx[i] >> yy[i];
	REP(id , 1 , n + 1){
		REP(i , x[id] , xx[id]) REP(j , y[id] , yy[id]) c[i + 1][j + 1] = 1;
		REP(i , y[id] , yy[id]) l[x[id] + 1][i + 1] = r[xx[id]][i + 1] = 1;
		REP(j , x[id] , xx[id]) d[j + 1][y[id] + 1] = u[j + 1][yy[id]] = 1;
	}
	REP(i , 1 , MAX) REP(j , 1 , MAX) l[i][j] += l[i][j - 1];
	REP(i , 1 , MAX) REP(j , 1 , MAX) r[i][j] += r[i][j - 1];
	REP(i , 1 , MAX) REP(j , 1 , MAX) c[i][j] += c[i][j - 1];
	REP(i , 1 , MAX) REP(j , 1 , MAX) c[i][j] += c[i - 1][j];
	REP(i , 1 , MAX) REP(j , 1 , MAX) u[i][j] += u[i - 1][j];
	REP(i , 1 , MAX) REP(j , 1 , MAX) d[i][j] += d[i - 1][j];
	REP(i , 1 , n + 1){
		REP(len , 0 , MAX){
			int tox = x[i] + len , toy = y[i] + len;
			if(l[x[i] + 1][toy + 1] - l[x[i] + 1][y[i]] != len + 1) break;
			if(d[tox + 1][y[i] + 1] - d[x[i]][y[i] + 1] != len + 1) break;
			if(query(x[i] , tox , y[i] , toy) != (len + 1) * (len + 1)) break;
			if(r[tox + 1][toy + 1] - r[tox + 1][y[i]] != len + 1) continue;
			if(u[tox + 1][toy + 1] - u[x[i]][toy + 1] != len + 1) continue;
			vector<int> sol;
			REP(j , 1 , n + 1){
				if( (x[i] <= x[j] && xx[j] <= tox + 1) == 0) continue;
				if( (y[i] <= y[j] && yy[j] <= toy + 1) == 0) continue;
				sol.pb(j);
			}
			cout << "YES " << sol.size() << endl;
			for(auto to : sol) cout << to << " " ; cout << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}