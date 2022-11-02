/*input
353637900000000 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300000
#define INF 0x3f3f3f3f
#define mod 1000000007

int n , k;
int ni[MAX];
void getcountmath(){
	ni[0] = ni[1] = 1;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
}
int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int32_t main(){
	IOS;
	cin >> n >> k;
	getcountmath();
	map<int , int> cc;	
	REP(i , 2 , n + 1){
		if(i * i > n) break;
		else if(n % i == 0){
			while(n % i == 0) cc[i] ++ , n /= i;
		}
	}
	if(n != 1) cc[n] ++;
	int ans = 1 , all = 1;
	for(auto to : cc){
		vector<int> sol;

		sol.pb(1);
		REP(i , 0 , to.S) sol.pb(sol.back() * (to.F % mod) % mod);
		// for(auto val : sol) cout << val << " "; cout << endl;
		REP(times , 2 , k + 1){
			REP(i , 1 , sol.size()) sol[i] = (sol[i] + sol[i - 1]) % mod;
			REP(i , 1 , sol.size()) sol[i] = sol[i] * ppow(i + 1 , mod - 2) % mod;
		}
		int sum = 0;
		REP(i , 0 , sol.size()) sum = (sum + sol[i]) % mod;

		ans = ans * sum % mod;
		all = all * sol.size();
	}
	cout << ans * ppow(all , mod - 2) % mod << endl;
    return 0;
}