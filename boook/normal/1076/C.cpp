/*input
7
69
0
1
4
5
999
1000
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
const int INF = 0x3f3f3f3f;

int t , n;
int32_t main(){
	cin >> t;
	REP(times , 0 , t){
		cin >> n;
		if(n == 0) cout << "Y 0 0" << endl;
		else if(n < 4) cout << "N" << endl;
		else {
			cout << "Y ";
			long double l = 2, r = 100000;
			REP(T , 0 , 100){
				long double mid = (l + r) / 2;
				if(mid * mid / (mid - 1) < n) l = mid;
				else r = mid;
			}
			printf("%.11Lf %.11Lf\n", l , (long double)n - l);
		}
	}
    return 0;
}