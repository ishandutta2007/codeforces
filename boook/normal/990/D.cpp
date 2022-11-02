/*input
1 1 1
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

int n , m , k , x[MAX][MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	if(m == 1 && k == 1){
		if(n <= 3 && n != 1) return cout << "NO" << endl , 0;
		cout << "YES" << endl;
		REP(i , 1 , n + 0) x[i][i + 1] = x[i + 1][i] = 1;
		REP(i , 1 , n + 1){
			REP(j , 1 , n + 1) cout << x[i][j];
			cout << endl;
		}
		return 0;
	}
	if(m != 1 && k != 1) return cout << "NO" << endl , 0;
	cout << "YES" << endl;
	int sw = 0;
	if(m == 1) sw = 1 , swap(m , k);
	REP(i , m + 1 , n + 1) x[m][i] = x[i][m] = 1;
	if(sw == 1){
		REP(i , 1 , n + 1) REP(j , 1 , n + 1){
			if(i == j) continue;
			else x[i][j] ^= 1;
		}
	}
	REP(i , 1 , n + 1){
		REP(j , 1 , n + 1) cout << x[i][j];
		cout << endl;
	}
    return 0;
}