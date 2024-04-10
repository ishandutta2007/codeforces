#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 700
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){}

void Init(){}

void Read(){}

void Solve(){}
LL n , m , mod;
string s;
int use[MAX];
LL dp[MAX][MAX];
LL DP(LL one , LL two){
	// DBGG(one , two);cout << "49" << endl;
	if(one == 0 && two == 0) return 1;
	else if(one < 0 || two < 0) return 0;
	else if(dp[one][two] != -1) return dp[one][two];
	else {
		// DBGG("54" , "");
		LL ans = 0 , lin = (one + two + two) / 2;

		if(one && two) ans += DP(one , two - 1) * one * two;
		if(one >= 2) ans += DP(one - 2 , two) * (one * (one - 1)) / 2;
		if(two >= 2) ans += DP(one + 2 , two - 2) * (two * (two - 1)) / 2;
		// DB4(one , two , ans % mod , "");
		return dp[one][two] = ans % mod;
	}
}
int main(){

	MEM(dp , -1);
	// mod = 100000008;
	// cout << DP(2 , 0) << endl;
	// cout << DP(4 , 0) << endl;
	// cout << DP(6 , 0) << endl;

	cin >> n >> m >> mod;
	LL one = 0 , two = 0;
	REP(i , m){
		cin >> s;
		REP(j , s.size()) if(s[j] == '1') use[j] ++;
	}
	REP(i , n)
		if(use[i] == 0) two ++;
		else if(use[i] == 1) one ++;
	// dp[0][0] = 1;
	// dp[2][0] = 1;
	// dp[0][1] = 1;
	// dp[3][1] = 3;
	// dp[0][2] = 2;
	// dp[2][1] = 2;
	// dp[2][2] =
	LL ans;
	if((one + two + two) & 1) ans = 0;
	else ans = DP(one , two);
	cout << ans << endl;
    return 0;
}