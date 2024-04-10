#include <bits/stdc++.h> 
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define ALL(i) i.begin() , i.end()
///---------------------
#define int long long
#define MAX 3030
#define INF 1000000000000000LL
using namespace std;
int n , m , x[MAX] , dp[MAX][MAX] , p[MAX];
vector<int> uni;
signed main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i] , x[i] -= i;
	REP(i , 1 , n + 1) uni.pb(x[i]);
	sort(ALL(uni));
	uni.resize(unique(ALL(uni)) - uni.begin());
	m = uni.size() , p[0] = INF;
	
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1) p[j] = min(p[j - 1] , dp[i - 1][j]);
		REP(j , 1 , m + 1) dp[i][j] = p[j] + abs(uni[j - 1] - x[i]);
	}
	int ans = INF;
	REP(j , 1 , m + 1) ans = min(ans , dp[n][j]);
	cout << ans << endl;
	return 0;
}