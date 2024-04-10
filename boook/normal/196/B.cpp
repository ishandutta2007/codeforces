/*input
5 4
##.#
##S#
#..#
..#.
#.##
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 2000
#define INF 0x3f3f3f3f

int n , m , X[] = {0 , 0 , -1 , 1} , Y[] = {-1 , 1 , 0 , 0};
PII dp[MAX][MAX];
string s[MAX];
void check(int x , int y){
	int tox = (x % n + n) % n;
	int toy = (y % m + m) % m;
	if(dp[tox][toy] != mp(INF , INF) && dp[tox][toy] != mp(x , y)){
		cout << "Yes" << endl;
		exit(0);
	}
	else dp[tox][toy] = mp(x , y);
}
void DFS(int x , int y){
	check(x , y);
	REP(i , 0 , 4){
		int xx = x + X[i] , yy = y + Y[i];
		int tox = (xx % n + n) % n;
		int toy = (yy % m + m) % m;
		if(s[tox][toy] == '#') continue;
		if(dp[tox][toy] != mp(xx , yy)) DFS(xx , yy);
	}
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 0 , n) REP(j , 0 , m) dp[i][j] = mp(INF , INF);
	REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] == 'S') DFS(i , j);
	cout << "No" << endl;
    return 0;
}