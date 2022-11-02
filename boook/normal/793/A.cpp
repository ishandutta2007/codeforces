#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define LL long long int
#define PII pair<int , int>
#define PLL pair< LL , LL >
#define VI vector< int > 
#define VLL vector< LL > 
#define VPII vector< PII >
#define VPLL vector< PLL >
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
#define int long long
#define MAX 200000
#define INF 0x3f3f3f3f


int n , k , ans = 0 , x[MAX] , mm;
main(){
	mm = 1000000000000LL;
	cin >> n >> k;
	int ok = 1;
	REP(i , n) cin >> x[i] , mm = min(mm , x[i]);
	REP(i , n){
		if((x[i] - mm) % k != 0) ok = 0;
		ans += (x[i] - mm) / k;
	}
	if(ok == 0) cout << -1 << endl;
	else cout << ans << endl;
}