#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 110
#define INF 0x3f3f3f3f
#define mod 1000003LL

int n , w , h;
vector<vector<int> > G(vector<vector<int> > a , vector<vector<int> > b){
	vector<vector<int> > ans(MAX , vector<int>(MAX)); 
	REP(i , 0 , w + 1) REP(j , 0 , w + 1){
		REP(k , 0 , w + 1){
			ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	return ans;
}
vector<vector<int> > solve(vector<vector<int> > v , int k){
	if(k == 1) return v;
	if(k % 2 == 0) return solve(G(v , v) , k / 2);
	if(k % 2 == 1) return G(solve(G(v , v) , k / 2) , v);
}
int32_t main(){
	cin >> n >> w >> h;
	vector<vector<int> > v(MAX , vector<int>(MAX)); 
	REP(i , 0 , w + 1) v[0][i] = 1;
	REP(i , 1 , w + 1) v[i][i - 1] = h;
	// REP(i , 0 , w + 1) {
	// 	REP(j , 0 , w + 1) cout << v[i][j] << " ";
	// 	cout << endl; 
	// }
	vector<vector<int> > vr = solve(v , n);
	int ans = 0;
	REP(i , 0 , w + 1){
		ans = (ans + vr[i][0]) % mod;
	}
	cout << ans << endl;
    return 0;
}