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

LL n , m , k , l;
int main(){
    cin >> n >> m >> k >> l;
    string ans;
    int now = 0 , ok = 1;
	REP(i , n){
		if(k > l){
			if(now < 0) now = 1 , ans += "G" , k--;
			else if(abs(now + 1) <= m) now ++ , ans += "G" , k--;
			else if(l) now = -1 , ans += "B" , l--;
			else ok = 0;
		}
		else if(k < l){
			if(now > 0) now = -1 , ans += "B" , l--;
			else if(abs(now - 1) <= m) now -- , ans += "B" , l--;
			else if(k) now = 1 , ans += "G" , k--;
			else ok = 0;
		}
		else {
			if(now > 0) now = -1 , ans += "B" , l--;
			else now = 1 , ans += "G" , k--;
		}
	}
	if(!ok) puts("NO");
	else cout << ans << endl;
    return 0;
}