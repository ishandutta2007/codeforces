/*input
3 2
111
1 2
3 3
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
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m , x[MAX] , two[MAX];
string s;
int32_t main(){
	IOS;
	two[0] = 1;
	REP(i , 1 , MAX) two[i] = two[i - 1] * 2 % mod;
	cin >> n >> m;
	cin >> s;
	REP(i , 0 , s.size()) x[i + 1] = x[i] + (s[i] == '1');
	REP(i , 1 , m + 1){
		int l , r;
		cin >> l >> r;
		int sum = x[r] - x[l - 1] , len = r - l + 1 , las = len - sum;
		int v1 = (two[sum] + mod - 1) % mod;
		int v2 = (two[las] + mod - 1) % mod * v1 % mod;
		// DB4("sum = " , sum , "las = " , las);
		// DB4("v1 = " , v1 , "v2 = " , v2);
		cout << (v1 + v2) % mod << endl;
	}
    return 0;
}