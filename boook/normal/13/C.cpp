#include <bits/stdc++.h> 
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define ALL(i) i.begin() , i.end()
///---------------------
#define int long long
#define MAX 5050
#define INF 10000000000000000LL
#define mod 1000000007LL
using namespace std;

int n , x[MAX] , dp[MAX] , p[MAX];
vector<int> uni;
signed main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) uni.pb(x[i]);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin()) , p[0] = INF;
	int m = uni.size();
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1) p[j] = min(p[j - 1] , dp[j]);
		REP(j , 1 , m + 1) dp[j] = p[j] + abs(uni[j - 1] - x[i]);
	}
	int ans = INF;
	REP(i , 1 , m + 1) ans = min(ans , dp[i]);
	cout << ans << endl;
	return 0;
}