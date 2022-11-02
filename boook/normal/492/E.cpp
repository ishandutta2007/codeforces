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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define debug 1

void Solve(){}
LL n , m , x , y;
LL k[MAX];
PLL xx[MAX];
PLL ab[MAX];
int main(){
	RLL(n , m);
	RLL(x , y);
	REP(i , n * 2){
		LL tmp = (i * x) % n;
		k[(n - tmp) % n] = i;
	}
	REP(i , m){
		LL q , w;
		RLL(q , w);
		ab[i] = mp(q , w);
		LL tmp = k[q];
		xx[i].A = (tmp * y + w) % n;
		xx[i].B = i;
	}
	sort(xx , xx + m);
	LL now = 0 , ans = 1;
	PLL good = ab[xx[0].B];
	REP(i , m - 1){
		if(xx[i].A != xx[i + 1].A){
			if(ans < i - now + 1){
				ans = i - now + 1;
				good = ab[xx[i].B];
			}
			now = i + 1;
		}
	}
	if(ans < m - 1 - now + 1){
		ans = m - 1 - now + 1;
		good = ab[xx[m - 1].B];
	}
	cout << good.A << " " << good.B << endl;
    return 0;
}