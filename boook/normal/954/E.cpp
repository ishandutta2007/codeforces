/*input
2 12
1 3
10 15
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
#define int int_fast64_t
#define MAX 200900
#define INF 0x3f3f3f3f

int n , k , x[MAX] , t[MAX];
double ans = 0;
vector<PII> sml , big;
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cin >> t[i];
	REP(i , 1 , n + 1){
		if(t[i] == k) ans += x[i];
		else if(t[i] < k) sml.pb(mp(t[i] , x[i]));
		else if(t[i] > k) big.pb(mp(t[i] , x[i]));
	}
	sort(ALL(sml) , greater<PII>());
	sort(ALL(big));
	int smlval = 0 , bigval = 0;
	for(auto to : sml) smlval += (k - to.A) * to.B;
	for(auto to : big) bigval += (to.A - k) * to.B;

	// DBGG(smlval , bigval);

	if(smlval >= bigval){
		for(auto to : big) ans += to.B;
		double las = bigval;
		for(auto to : sml){
			double tmp = min(las , double(k - to.A) * to.B);
			las -= tmp;
			ans += tmp / (k - to.A);
		}
	}
	else if(bigval > smlval){
		for(auto to : sml) ans += to.B;
		double las = smlval;
		for(auto to : big){
			double tmp = min(las , double(to.A - k) * to.B);
			las -= tmp;
			ans += tmp / (to.A - k);
 		}
	}
	printf("%.11f\n", ans);
    return 0;
}