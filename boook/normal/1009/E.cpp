/*input
4
1 3 3 7
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 998244353LL

int two[MAX];
int n , x[MAX];
int32_t main(){
	IOS;
	two[0] = 1;
	REP(i , 1 , MAX) two[i] = (two[i - 1] + two[i - 1]) % mod;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int ans = 0 , pre = 0;
	REP(i , 1 , n + 1){
		int now = pre + x[i];
		ans = (ans + now * two[n - i]) % mod;
		pre = (pre * 2 + x[i]) % mod;
	}
	cout << ans << endl;
    return 0;
}