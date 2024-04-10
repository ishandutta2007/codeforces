/*input
5
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

int n , x[MAX][MAX];
int32_t main(){
	IOS;
	cin >> n;
	if(n == 4) cout << -1 << endl;
	else {
		REP(i , 0 , n){
			REP(j , 0 , n){
				if((i + 1) % n == j) x[i][j] = 1;
				else if(abs(j - i) == 1 || abs(j - i) == n - 1);
				else if(i % 2 == j % 2 && i < j) x[i][j] = 1;
				else if(i % 2 != j % 2 && i > j) x[i][j] = 1;
			}
		}
		REP(i , 0 , n){
			REP(j , 0 , n) cout << x[i][j] << " ";
			cout << endl;
		}
	}
    return 0;
}