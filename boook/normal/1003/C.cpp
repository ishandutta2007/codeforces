/*input
4 3
3 4 1 2	
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , k , x[MAX];
int32_t main(){
	// IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i] , x[i] += x[i - 1];
	double ans = 0;
	REP(i , 1 , n + 1) REP(j , i , n + 1){
		int len = j - i + 1;
		if(len >= k){
			double v1 = x[j] - x[i - 1];
			ans = max(ans , v1 / len);
		}
	}
	printf("%.11f\n", ans);
    return 0;
}