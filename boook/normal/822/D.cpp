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
#define MAX 5000900
#define INF 0x3f3f3f3f
#define mod 1000000007

int p[MAX] , dv[MAX] , po;
int dp[MAX];
void pre(){
	REP(i , 2 , MAX){
		if(dv[i] == 0) dv[i] = i , p[po++] = i;
		REP(j , 0 , po){
			int tmp = p[j] * i;
			if(tmp >= MAX) break;
			dv[tmp] = p[j];
			if(i % p[j] == 0) break; 
		}
	}
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 3;
	REP(i , 4 , MAX){
		dp[i] = (i * (i - 1) / 2) % mod;
		if(dv[i] != i) {
			int tmp = dv[i];
			dp[i] = min((i * (i - 1) / 2) , dp[tmp] * (i / tmp) + dp[i / tmp]) % mod;
		}
			// DB4("dp[" , i , "] = " , dp[i]);
	}
}
int n , m , k;
int32_t main(){
	pre();
	cin >> n >> m >> k;
	int v = 1 , ans = 0;
	REP(i , m , k + 1){
		ans = (ans + v * dp[i]) % mod;
		v = v * n % mod;
	}
	cout << ans << endl;
    return 0;
}