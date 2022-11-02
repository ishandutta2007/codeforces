/*input
4
4 3 2 5
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
#define MAX 200900
#define INF 1000000000000000000LL
#define mid ((l + r) >> 1)

int base[MAX] , a[MAX] , x[MAX] , b[MAX];

int n , ary[MAX] , pre[MAX] , dp[MAX];

int cmp1(int q , int w){
	if(a[q] != a[w]) return a[q] < a[w];
	if(a[q] == a[w]) return b[q] < b[w];
}
int cmp2(int q , int w){ return x[q] < x[w]; }
void solve(int l , int r){
	if(l == r) return ;
	vector<int> lth;
	vector<int> rth;
	REP(i , l + 0 , mid + 1) lth.pb(i);
	REP(i , mid + 1 , r + 1) rth.pb(i);
	sort(ALL(lth) , cmp1);
	sort(ALL(rth) , cmp2);
	int lpo = 0;
	REP(i , 0 , lth.size()){
		int to = lth[i];
		if(a[to] * x[rth[0]] + b[to] > a[lth[lpo]] * x[rth[0]] + b[lth[lpo]]) lpo = i;
	}
	for(auto i : rth){
		int now = a[lth[lpo]] * x[i] + b[lth[lpo]];
		while(lpo + 1 < lth.size() && a[lth[lpo + 1]] * x[i] + b[lth[lpo + 1]] >= now){
			now = a[lth[lpo + 1]] * x[i] + b[lth[lpo + 1]];
			lpo ++;
		}
		// if(now > dp[i]) DB4("update = " , now + base[i] , i , lth[lpo]);
		dp[i] = max(dp[i] , now);
	}
	solve(l , mid + 0);
	solve(mid + 1 , r);
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> ary[i];
	REP(i , 1 , n + 1) pre[i] = pre[i - 1] + ary[i];

	int ans = 0;
	REP(i , 1 , n + 1) base[i] = -ary[i] * i + pre[i - 1];
	REP(i , 1 , n + 1) a[i] = i;
	REP(i , 1 , n + 1) x[i] = ary[i];
	REP(i , 1 , n + 1) b[i] = -pre[i - 1];
	REP(i , 1 , n + 1) dp[i] = -INF;

	// REP(i , 1 , n + 1) REP(j , 1 , i){
	// 	dp[i] = max(dp[i] , a[j] * x[i] + b[j]);
	// }
	solve(1 , n);
	REP(i , 1 , n + 1) ans = max(ans , dp[i] + base[i]);

	REP(i , 1 , n + 1) base[i] = -pre[i];
	REP(i , 1 , n + 1) a[i] = ary[i];
	REP(i , 1 , n + 1) x[i] = i;
	REP(i , 1 , n + 1) b[i] = pre[i] - ary[i] * i;
	REP(i , 1 , n + 1) dp[i] = -INF;

	// REP(i , 1 , n + 1) REP(j , 1 , i){
	// 	dp[i] = max(dp[i] , a[j] * x[i] + b[j]);
	// }
	solve(1 , n);
	REP(i , 1 , n + 1) ans = max(ans , dp[i] + base[i]);

	// DBGG("ans = " , ans);
	REP(i , 1 , n + 1) ans += ary[i] * i;
	cout << ans << endl;
    return 0;
}