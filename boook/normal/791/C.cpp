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
#define MAX 1000
#define INF 0x3f3f3f3f
#define debug 1

int n , m , use[MAX];
string ans[MAX];
string F(int now){
	string ans;
	if(now < 26) ans += 'A' + now;
	else ans += 'B' , ans += 'a' + now - 25;
	return ans;
}
int main(){
	// REP(i , 51) cout << F(i) << endl;
	while(cin >> n >> m){
		string s;
		REPNM(i , m - 1 , n){
			cin >> s;
			if(s == "YES") use[i] = 1;
			else use[i] = 0;
		}
		REP(i , m - 1) ans[i] = F(i);
		REPNM(i , m - 1 , n){
			if(use[i]) ans[i] = F(i);
			else ans[i] = ans[i - m + 1];
		}
		REP(i , n) cout << ans[i] << " ";
		cout  << endl;
	}
    return 0;
}