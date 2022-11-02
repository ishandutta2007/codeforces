/*input
4 12
15 7 4 19 3 30 14 1 5 23 17 25
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
#define MAX 500900
#define INF 1000000000000000LL

int n , k , x[MAX];
PII dp[MAX];
PII judge(int cost){
	REP(i , 2 , n + 1)
		dp[i] = min(dp[i - 1] , mp(dp[i - 2].A + cost + x[i] - x[i - 1] , dp[i - 2].B + 1));
	return dp[n];
}
int32_t main(){
	IOS;
	cin >> k >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	sort(x + 1 , x + 1 + n);
	int l = -INF , r = INF;
	while(r - l > 1){
		int mid = l + (r - l) / 2;
		PII res = judge(mid);
		// DB4(mid , res.A , res.B , res.A - mid * res.B);
		if(res.B == k){
			cout << res.A - mid * res.B << endl;
			return 0;
		}
		else if(res.B > k) l = mid;
		else if(res.B < k) r = mid;
	}
	// cout << "here" << endl;
	PII res = judge(r);
	cout << res.A - k * r << endl;
    return 0;
}