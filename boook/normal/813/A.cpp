/*input
2
3 4
2
1 4
7 9
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , l[MAX] , r[MAX]; 

int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int sum = 0;
	REP(i , 1 , n + 1) sum += x[i];
	cin >> m;
	REP(i , 1 , m + 1) cin >> l[i] >> r[i];
	REP(i , 1 , m + 1){
		if(sum <= r[i]){
			cout << max(l[i] , sum) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}