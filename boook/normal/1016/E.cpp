/*input
-3 1 6
2
2 4
6 7
5
3 1
1 3
6 1
6 4
7 6
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
#define MAX 200090
#define INF 0x3f3f3f3f

int y , a , b;
int n;
int lr[MAX][2] , sum[MAX];
int q;
int ql , qr;
int32_t main(){
	scanf("%lld%lld%lld" , &y , &a , &b);
	// cin >> y >> a >> b;
	scanf("%lld" , &n);
	// cin >> n;

	REP(i , 1 , n + 1) scanf("%lld%lld" , &lr[i][0] , &lr[i][1]);
	// REP(i , 1 , n + 1) cin >> lr[i][0] >> lr[i][1];
	REP(i , 1 , n + 1) sum[i] = sum[i - 1] + lr[i][1] - lr[i][0];
	scanf("%lld" , &q);
	// cin >> q;
	REP(i , 1 , q + 1){
		// cin >> ql >> qr;
		scanf("%lld%lld" , &ql , &qr);
		double ans = sum[n];
		// DBGG("ans = " , ans);
		int now = 0;

		RREP(j , 20 , 0){
			int to = now + (1 << j);
			if(to <= n){
				// rr = y * (ql - lr[to][1]) / qr + lr[to][1];
				if(y * (ql - lr[to][1]) <= (a - lr[to][1]) * qr) now = to;
			}
		}
		ans -= sum[now];
		// DBGG("now = " , now);
		if(now + 1 <= n){
			double idx = lr[now + 1][0];
			double tmp = (double)a - (double)y * ((double)ql - a) / (qr - y);
			// DBGG("tmp = " , tmp);
			ans -= max(0.0 , tmp - idx);
			// double rr = y * (ql - lr[now + 1][1]) / qr + lr[now + 1][1];
			// ans -= max(0.0 , rr - (double)a - rr);
		}

		// DBGG("ans = " , ans);

		now = n + 1;
		RREP(j , 20 , 0){
			int to = now - (1 << j);
			if(to >= 1){
				// ll = y * (ql - lr[to][1]) / qr + lr[to][1];
				if(y * (ql - lr[to][0]) >= (b - lr[to][0]) * qr) now = to;
			}
		}
		ans -= sum[n] - sum[now - 1];
		if(now - 1 >= 1){
			double idx = lr[now - 1][1];
			double tmp = (double)b - (double)y * ((double)ql - b) / (qr - y);
			// double ll = y * (ql - lr[now - 1][0]) / qr + lr[now + 1][0];
			// DBGG("tmp = " , idx);
			ans -= max(0.0 , idx - tmp);
		}
		// printf("%.11f\n", ans);
		printf("%.11f\n", ans * (((double)(qr - y) / (double)qr)));
		// return 0;
	}
    return 0;
}