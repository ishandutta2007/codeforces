/*input
3 4 3 1
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
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m , q , w;

vector<vector<int>> mul(vector<vector<int>> a , vector<vector<int>> b){
	vector<vector<int>> ans(2 , vector<int>(2));
	REP(i , 0 , 2) REP(j , 0 , 2){
		REP(k , 0 , 2) ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
	}
	return ans;
}
vector<vector<int>> ppow(vector<vector<int>> a , int k){
	if(k == 1) return a;
	if(k % 2 == 0) return ppow(mul(a , a) , k >> 1);
	if(k % 2 == 1) return mul(ppow(mul(a , a) , k >> 1) , a);
}
int32_t main(){
	IOS , cin >> q >> w >> n >> m;
	vector<vector<int>> a(2 , vector<int>(2));
	a[0][0] = q , a[0][1] = w;
	a[1][0] = 0 , a[1][1] = 1;
	a = ppow(a , n);
	cout << (m * a[0][0] + a[0][1]) % mod << endl;
    return 0;
}