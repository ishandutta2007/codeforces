/*input
5 3 3 3 3
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
#define PII pair<double , double>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define INF 0x3f3f3f3f

double r , a , b , x , y;
int32_t main(){
	cin >> r >> a >> b >> x >> y;
	double val = (a - x) * (a - x) + (b - y) * (b - y);
	if(val >= r * r){
		printf("%.11f %.11f %.11f\n" , a , b , r);
	}
	else {
		if(val <= 1e-9){
			printf("%.11f %.11f %.11f\n" , 1.0 * a + 1.0 * r / 2 , b , r / 2);
		}
		else {
			PII d = mp(a - x , b - y);
			double ll = 0 , rr = 1e6 , xx , yy;
			REP(times , 0 , 100){
				double mid = (ll + rr) / 2;
				xx = 1.0 * d.A * mid + a;
				yy = 1.0 * d.B * mid + b;
				double vv = (xx - a) * (xx - a) + (yy - b) * (yy - b);
				// cout << ll << " " << rr << endl;
				// cout << xx << " " << yy << " " << vv << endl;
				if(vv >= r * r) rr = mid;
				else ll = mid;
			}
			double tmp = sqrt(val);
			// cout << xx << " " << yy << endl;
			printf("%.11f %.11f %.11f\n" , (xx + x) / 2 , (yy + y) / 2 , (tmp + r) / 2);
		}
	}
    return 0;
}