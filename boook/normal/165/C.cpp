#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< LL > VLL;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

LL n;
string s;
VLL x;
LL solve(){
	s += "1";
	LL ans = 0 , now = 0;
	LREP(i , s.size()){
		if(s[i] == '0') now++;
		else ans += (now * (now + 1)) / 2 , now = 0;
	}
	return ans;
}
int main(){
    cin >> n >> s;
    if(n == 0) cout << solve() << endl;
   	else {
	    x.pb(-1);
	    LREP(i , s.size()){
	    	if(s[i] == '1') x.pb(i);
	    }
	    x.pb(s.size());
	    if(x.size() < n + 2) cout << 0 << endl;
	    else {
	    	LL ans = 0;
	    	LREPNM(i , n , x.size() - 1){
	    		LL tma = x[i + 1] - x[i];
	    		LL tmb = x[i - n + 1] - x[i - n];
	    		ans += tma * tmb;
	    	}
	    	cout << ans << endl;
	    }
    }
    return 0;
}