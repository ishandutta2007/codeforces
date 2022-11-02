/*input
6 3
1 3 4 6 9 10
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
#define MAX 1000
#define INF 0x3f3f3f3f

int n , x[MAX] , k;
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1){
		int in;cin >> in;
		x[in] ++;
	}
	REP(i , 1 , MAX) x[i] += x[i - 1];
	int big = 0;
	REP(i , k , 1000) big = max(big , x[i] - x[i - k - 1]);
	cout << n - big << endl;
    return 0;
}