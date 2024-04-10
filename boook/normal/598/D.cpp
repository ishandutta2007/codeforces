/*input
5 6 3
******
*..*.*
******
*....*
******
2 2
2 5
4 3
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

string s[MAX];

int n , m , k , vis[MAX][MAX] , use[MAX][MAX] , ans[MAX][MAX] , usepo = 1 , cnt = 0;
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
void DFS1(int a , int b){
	vis[a][b] = usepo;
	// DBGG(a , b);
	REP(i , 0 , 4){
		int tox = a + X[i];
		int toy = b + Y[i];
		if(tox >= 1 && tox <= n && toy >= 1 && toy <= m);
		else continue;

		if(s[tox][toy] == '*'){
			// if(use[tox][toy] != usepo){
				cnt ++;
				// use[tox][toy] = usepo;
			// }
		}
		if(s[tox][toy] == '.'){
			if(vis[tox][toy] == 0){
				DFS1(tox , toy);
			}
		}
	}
}
void DFS2(int a , int b , int val){
	ans[a][b] = val;
	REP(i , 0 , 4){
		int tox = a + X[i];
		int toy = b + Y[i];
		if(tox >= 1 && tox <= n && toy >= 1 && toy <= m);
		else continue;

		if(s[tox][toy] == '.'){
			if(ans[tox][toy] == -1){
				DFS2(tox , toy , val);
			}
		}
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> s[i] , s[i] = " " + s[i];

	MEM(ans , -1);
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1){
			if(s[i][j] == '.' && vis[i][j] == 0){
				usepo ++ , cnt = 0;
				DFS1(i , j);
				usepo ++;
				// DB4(i , j , cnt , "");
				DFS2(i , j , cnt);
			}
		}
	}
	REP(i , 1 , k + 1){
		int a , b;
		cin >> a >> b;
		cout << ans[a][b] << endl;
	}
    return 0;
}