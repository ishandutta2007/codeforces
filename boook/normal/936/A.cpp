/*input
4 2 20
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
#define MAX 
#define INF 0x3f3f3f3f

int a , b , c;
int32_t main(){

	cin >> a >> b >> c;
	int h = (a / b + (a % b != 0)) * b;
	// cout << "h = " << h << endl;

	long double one = (long double)a + (long double)(h - a) / 2;
	// cout << "one = " << one << endl;

	long double l = 0 , r = c + c + c;
	REP(times , 0 , 200){
		long double mid = (l + r) / 2;

	// long double mid = 17;
		long double v1 = floor(mid / h) , v2 = mid - v1 * h;
		long double val = 0;

// DBGG("v2 = " , v2);
		val += one * v1;
		long double sml = min((long double)a , v2);
		v2 -= sml;
		val += sml;
		val += v2 / 2;

		if(val >= c) r = mid;
		else l = mid;
		// DBGG("val = " , val);
		// return 0;
	}
	printf("%.11Lf\n", l);
    return 0;
}