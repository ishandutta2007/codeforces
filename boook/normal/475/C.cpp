/*input
4 5
XXXX.
XXXX.
.XX..
.XX..
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

string s[MAX];
int p[MAX][MAX] , n , m;
int GET(int a , int b , int x , int y){
	int tox = a + x - 1 , toy = b + y - 1;
	return p[tox][toy] - p[a - 1][toy] - p[tox][b - 1] + p[a - 1][b - 1];
}
int check(int a , int b , int x , int y , int sum){
	if(a + x - 1 == n && b + y - 1 == m) return sum == p[n][m];
	int u = GET(a + 1 , b , x , y);
	int r = GET(a , b + 1 , x , y);
	if(u == x * y && r != x * y) return check(a + 1 , b , x , y , sum + y);
	if(u != x * y && r == x * y) return check(a , b + 1 , x , y , sum + x);
	if(u != x * y && r != x * y) return sum == p[n][m];
	else return 0;
}
int32_t main(){
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) p[i][j] = s[i - 1][j - 1] == 'X';
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) p[i][j] += p[i][j - 1];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) p[i][j] += p[i - 1][j];

	int a , b;
	RREP(i , n , 1) RREP(j , m , 1) if(s[i - 1][j - 1] == 'X') a = i , b = j;
	int ans = INF;
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1){
			if(i + a - 1 > n || j + b - 1 > m) continue;
			if(GET(a , b , i , j) != i * j) continue;
			if(check(a , b , i , j , i * j)) ans = min(ans , i * j);
		}
	}
	cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}