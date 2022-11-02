/*input
1 1 0
0
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
#define int long long
#define MAX 100
#define INF 0x3f3f3f3f

int n , m , k , a[MAX][MAX] , ans = 0;
int all , v1;
map<pair<PII , int> , int> cc;
void DFS1(int x , int y , int val){
	if(x + y == v1 - 1) cc[mp(mp(x , y) , val)] ++;
	else {
		if(x + 1 != n) DFS1(x + 1 , y , val ^ a[x + 1][y]);
		if(y + 1 != m) DFS1(x , y + 1 , val ^ a[x][y + 1]);
	}
}
void DFS2(int x , int y , int val){
	if(x + y == v1 - 1){
		int need = val ^ a[x][y] ^ k;
		ans += cc[mp(mp(x , y) , need)];
	}
	else {
		if(x - 1 != -1) DFS2(x - 1 , y , val ^ a[x - 1][y]);
		if(y - 1 != -1) DFS2(x , y - 1 , val ^ a[x][y - 1]);
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 0 , n) REP(j , 0 , m) cin >> a[i][j];
	all = n + m - 1 , v1 = max(1LL , all / 2);
	DFS1(0 , 0 , a[0][0]);
	DFS2(n - 1 , m - 1 , a[n - 1][m - 1]);
	cout << ans << endl;
    return 0;
}