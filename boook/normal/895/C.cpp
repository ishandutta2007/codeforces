/*input
13
64 65 40 26 36 46 53 31 63 11 2 46 59
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
#define MAX 2000000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int p[19] = { 2 ,  3 ,  5 ,  7 , 11 , 13 , 17 , 19 , 23 , 
	  	29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67};
int n , dp[MAX] , tmp[MAX] , x[MAX] , cnt[MAX] , two[MAX];

int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1){
		cin >> x[i];
		cnt[x[i]] ++;
	}
	two[0] = dp[0] = 1;
	REP(i , 1 , MAX) two[i] = two[i - 1] * 2 % mod;
	REP(ii , 1 , 70 + 1){
		if(cnt[ii] == 0) continue;
		REP(i , 0 , (1 << 19)) tmp[i] = 0;

		int ttt = ii , pat = 0;
		REP(i , 0 , 19){
			pat = pat * 2;
			while(ttt % p[i] == 0) pat ^= 1 , ttt /= p[i];
		}
		REP(i , 0 , (1 << 19)) tmp[i ^ pat] = dp[i] * two[cnt[ii] - 1] % mod;;
		REP(i , 0 , (1 << 19)) dp[i] = dp[i] * two[cnt[ii] - 1] % mod;
		REP(i , 0 , (1 << 19)) dp[i] = (dp[i] + tmp[i]) % mod;
	}
	cout << dp[0] - 1 << endl;
    return 0;
}