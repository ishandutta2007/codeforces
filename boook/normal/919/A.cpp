/*input
2 1
99 100
98 99
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
#define int long long
#define MAX 10900
#define INF 0x3f3f3f3f

int n;
double m , x[MAX][2];
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	double ans = 1e100;
	REP(i , 1 , n + 1){
		ans = min(ans , m * x[i][0] / x[i][1]);
	}
	printf("%.11f\n", ans);
    return 0;
}