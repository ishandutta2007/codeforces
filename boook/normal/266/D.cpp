/*input
3 2
1 2 100
2 3 1
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
#define MAX 220
#define INF 0x3f3f3f3f

int n , m , dis[MAX][MAX] , e[MAX * MAX][2] , c[MAX * MAX];
PII tmp[MAX];
double ans = 1e10;
void update(double a , double b , double c){
	double val = (a + b + c) / 2;
	if(val >= a && val >= b) ans = min(ans , val);
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) dis[i][j] = INF;
	REP(i , 1 , n + 1) dis[i][i] = 0;
	REP(i , 1 , m + 1){
		cin >> e[i][0] >> e[i][1] >> c[i];
		dis[e[i][0]][e[i][1]] = dis[e[i][1]][e[i][0]] = c[i];
	}
	REP(k , 1 , n + 1) REP(i , 1 , n + 1) REP(j , 1 , n + 1)
		dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);

	REP(i , 1 , m + 1){
		int a = e[i][0] , b = e[i][1];
		REP(j , 1 , n + 1) tmp[j] = mp(dis[a][j] , dis[b][j]);
		sort(tmp + 1 , tmp + 1 + n);
		RREP(j , n , 1) tmp[j].B = max(tmp[j].B , tmp[j + 1].B);
		REP(j , 1 , n + 1) update(tmp[j].A , tmp[j + 1].B , c[i]);
	}
	cout << ans << endl;
    return 0;
}