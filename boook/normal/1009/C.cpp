/*input
99999 1
1 1000
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
#define INF 0x3f3f3f3f

int n , m;
__float128 ans = 0;
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , m + 1){
		double a , d;
		cin >> a >> d;
		ans += a;
		if(d > 0){
			__float128 tmp = (__float128)(n - 1) / 2 * d;
			ans += tmp;
		}
		if(d < 0){
			int v1 = (n - 1) / 2 , v2 = (n - 1) - v1;
			__float128 tmp = v1 * (v1 + 1) / 2 + v2 * (v2 + 1) / 2;
			ans += tmp * d / n;
		}
	}
	printf("%.11Lf\n", (long double)ans);
    return 0;
}