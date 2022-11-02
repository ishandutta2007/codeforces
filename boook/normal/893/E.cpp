/*input
2
6 3
4 2
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int t , n , m;
int gi[MAX] , ni[MAX] , two[MAX];
void solveinit(){
	gi[0] = ni[0] = ni[1] = two[0] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;
	REP(i , 1 , MAX) two[i] = two[i - 1] * 2 % mod;
}
int C(int a , int b){
	if(a < b) return 0;
	return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
int32_t main(){
	solveinit();

	IOS , cin >> t;
	REP(times , 1 , t + 1){
		cin >> n >> m;
		int ans = 1;
		REP(i , 2 , n + 1){
			if(i * i > n) break;
			if(n % i == 0){
				int cnt = 0;
				while(n % i == 0){
					n /= i , cnt ++;
				}
				ans = ans * C(m + cnt - 1 , cnt) % mod;
			}
		}
		if(n != 1) ans = ans * m % mod;
		if(n % 2 == 1){
			int tmp = two[m] * ni[2] % mod;
			ans = ans * tmp % mod;
		}
		else {
			int tmp = two[m - 1];
			ans = (ans * tmp) % mod;
		}
		cout << ans << endl;
	}
    return 0;
}