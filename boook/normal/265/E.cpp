/*input
4 1
-3 6 -1 2
1 2 3 1
1 -1
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
#define MAX 100900
#define INF 1e17

int n , m , v[MAX] , c[MAX] , dp[MAX];
void solve(PII &fir , PII &sec , PII val){
	if(val.B == fir.B){
		fir.A = max(fir.A , val.A);
		if(sec > fir) swap(sec , fir);
		return;
	}
	if(val.B == sec.B){
		sec.A = max(sec.A , val.A);
		if(sec > fir) swap(sec , fir);
		return;
	}
	if(val > sec) swap(val , sec);
	if(sec > fir) swap(sec , fir);
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> v[i];
	REP(i , 1 , n + 1) cin >> c[i];
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;

		int ans = 0;
		REP(i , 1 , n + 1) dp[i] = -INF;
		PII fir = mp(-INF , -INF) , sec = mp(-INF , -INF);
		REP(i , 1 , n + 1){
			int big = max(v[i] * b , dp[c[i]] + v[i] * a);
			if(fir.B == c[i]) big = max(big , sec.A + v[i] * b);
			if(fir.B != c[i]) big = max(big , fir.A + v[i] * b);
			dp[c[i]] = max(dp[c[i]] , big);
			solve(fir , sec , mp(big , c[i]));
			ans = max(ans , big);
		}
		cout << ans << endl;
	}
    return 0;
}