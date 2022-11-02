/*input
6 2
5 5 6 8 3 12
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

int n , r , a[MAX];
long double x[MAX] , ans[MAX];
int32_t main(){
	cin >> n >> r;
	REP(i , 0 , n) cin >> a[i];
	REP(i , 0 , n) x[i] = a[i];

	ans[0] = r;
	REP(i , 1 , n){
		int ok = 1;
		long double tmp = -1e9;
		REP(j , 0 , i){
			if(abs(a[i] - a[j]) > r + r) continue;
			else {
				ok = 0;
				long double ll = ans[j] , rr = 1e9;
				REP(times , 0 , 50){
					long double mid = (ll + rr) / 2.0;
					long double dis = (x[i] - x[j]) * (x[i] - x[j])
							   + (mid - ans[j]) * (mid - ans[j]);
					if(dis > 4 * r * r) rr = mid;
					else ll = mid;
				}
				// DBGG(i , j);
				tmp = max(tmp , ll);
			}
		}
		if(ok) ans[i] = r;
		else ans[i] = tmp;
	}

	REP(i , 0 , n){
		printf("%.011Lf ", ans[i]);
	} puts("");
    return 0;
}