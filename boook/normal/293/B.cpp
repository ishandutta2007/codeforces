/*input
2 6 10
1 2 3 4 5 6
0 0 0 0 0 0
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
#define MAX 105
#define INF 0x3f3f3f3f
#define mod 1000000007LL


int n , m , k , a[MAX][MAX] , p[MAX][MAX];
int one[MAX * MAX * MAX] , col[MAX];
int DFS(int x , int y){
	if(y == m + 1) x ++ , y = 1;
	if(x == n + 1) return 1;
	int ans = 0 , first = -1 , use = p[x - 1][y] | p[x][y - 1];
	if(n - x + m - y + 1 > k - one[use]) return 0;
	REP(i , 1 , k + 1){
		if(use & (1 << i)) continue;
		if(a[x][y] == 0 || a[x][y] == i){
			p[x][y] = use | (1 << i);
			col[i] ++;
			if(col[i] == 1){
				if(first == -1) first = DFS(x , y + 1);
				ans = (ans + first) % mod;
			}
			else ans = (ans + DFS(x , y + 1)) % mod;
			col[i] --;
		}
	}
	return ans;
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , 1000000){
		if(i % 2 == 0) one[i] = one[i >> 1];
		if(i % 2 == 1) one[i] = one[i >> 1] + 1;
	}
	if(n + m - 1 > k) return cout << 0 << endl , 0;
	else {
		REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> a[i][j];
		REP(i , 1 , n + 1) REP(j , 1 , m + 1) col[a[i][j]] ++;
		cout << DFS(1 , 1) << endl;
	}
    return 0;
}