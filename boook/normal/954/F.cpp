/*input
3 5
1 2 3
2 2 3
3 2 3
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
#define MAX 100000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

vector<vector<int>> mul(vector<vector<int>> a , vector<vector<int>> b){
	vector<vector<int>> ans(3 , vector<int>(3));
	REP(i , 0 , 3) REP(j , 0 , 3) REP(k , 0 , 3)
		ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
	return ans;
}
vector<vector<int>> ppow(vector<vector<int>> a , int k){
	if(k == 1) return a;
	if(k % 2 == 0) return     ppow(mul(a , a) , k >> 1);
	if(k % 2 == 1) return mul(ppow(mul(a , a) , k >> 1) , a);
}
int n , k , x[MAX][3] , add[MAX];
vector<int> uni;
int32_t main(){
	IOS;
	cin >> n >> k;
	uni.pb(1) , uni.pb(k);
	REP(i , 0 , n) REP(j , 0 , 3) cin >> x[i][j];
	REP(i , 0 , n) REP(j , 1 , 3) uni.pb(x[i][j]);
	REP(i , 0 , n) uni.pb(x[i][1] - 1);
	sort(ALL(uni));
	uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 0 , n) REP(j , 1 , 3) x[i][j] = lower_bound(ALL(uni) , x[i][j]) - uni.begin();
	REP(i , 0 , n) REP(j , x[i][1] , x[i][2] + 1) add[j] |= (1 << (x[i][0] - 1));

	// REP(i , 0 , n){REP(j , 0 , 3) cout << x[i][j] << " ";cout << endl; }

	vector<int> ans(3); ans[1] = 1;
	REP(i , 1 , uni.size()){
		vector<vector<int>> trs(3 , vector<int>(3));
		// DBGG("add[i] = " , add[i]);
		if((add[i] & 1) == 0) trs[0][0] = trs[0][1] = 1;
		if((add[i] & 2) == 0) trs[1][0] = trs[1][1] = trs[1][2] = 1;
		if((add[i] & 4) == 0)             trs[2][1] = trs[2][2] = 1;

		// REP(ii , 0 , 3){ REP(jj , 0 , 3) cout << trs[ii][jj] << " "; cout << endl; }cout << "---\n"; 
		trs = ppow(trs , uni[i] - uni[i - 1]);
	
		vector<int> p(3);
		// REP(ii , 0 , 3) cout << ans[ii] << " "; cout << endl;
		REP(ii , 0 , 3) REP(jj , 0 , 3) p[ii] = (p[ii] + ans[jj] * trs[ii][jj]) % mod;
		ans = p;

		// REP(ii , 0 , 3) cout << p[ii] << " "; cout << endl;
		// cout << endl;
	}
	cout << ans[1] << endl;
    return 0;
}