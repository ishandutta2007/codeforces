/*input
3 2 1
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
#define MAX 4040
#define INF 0x3f3f3f3f
#define mod 1000000009LL

int n , m , k , c[MAX][MAX] , gi[MAX];

int32_t main(){
	IOS;
	gi[0] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 0 , MAX){
		REP(j , 0 , i + 1){
			if(j == 0 || j == i) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	cin >> n >> m >> k;
	int ans = 0;
	REP(i , 1 , k + 1){
		int base = c[k - i + i - 1][i - 1] , las = n - i;
		if(las >= 2 && m - las >= 0){
			ans = (ans + base * (las - 1) % mod * c[m - las + las - 1][las - 1]) % mod;
		}
	}
	cout << ans * gi[k] % mod * gi[m] % mod << endl;
    return 0;
}