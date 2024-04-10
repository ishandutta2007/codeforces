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
#define MAX 500900
#define INF 0x3f3f3f3f
#define N 50000000LL

LL n , x[MAX] , pr[MAX] , ba[MAX] , d[MAX];
__gnu_pbds::priority_queue<PLL>::point_iterator po[MAX];
__gnu_pbds::priority_queue<PLL> pq;
LL TR(LL now) { return now >= 1000090 ? (-now + N) : now; }
int main(){
    RL(n);
    REPNM(i , 1 , n + 1) RL(x[i]);
    REPNM(i , 2 , n) pr[i] = i - 1 , ba[i] = i + 1;
    REPNM(i , 2 , n){
    	LL tmp = min(x[pr[i]] , x[ba[i]]);
    	d[i] = tmp;
    	// DBGG(i , tmp);
    	if(x[i] <= tmp) po[i] = pq.push(mp(N - tmp , i));
    	else po[i] = pq.push(mp(tmp , i));
    }
    LL ans = 0;
    while(pq.size()){
    	PLL tmp = pq.top() ; pq.pop();
    	ans += TR(tmp.A);
    	// DB4(55 , TR(tmp.A) , tmp.B , "");
    	int now = tmp.B;
    	if(ba[now] != n){
    		d[ba[now]] = min(x[ba[ba[now]]] , x[pr[now]]);
    		pr[ba[now]] = pr[now];
    		if(x[ba[now]] <= d[ba[now]]) pq.modify(po[ba[now]] , mp(N - d[ba[now]] , ba[now]));
    		else pq.modify(po[ba[now]] , mp(d[ba[now]] , ba[now]));
    	}
    	if(pr[now] != 1){
    		d[pr[now]] = min(x[pr[pr[now]]] , x[ba[now]]);
    		ba[pr[now]] = ba[now];
    		// DB4("modify = " , d[pr[now]] , pr[now] , "");
    		if(x[pr[now]] <= d[pr[now]]) pq.modify(po[pr[now]] , mp(N - d[pr[now]] , pr[now]));
    		else pq.modify(po[pr[now]] , mp(d[pr[now]] , pr[now]));
    	}
    }
    printf("%lld\n", ans);
    return 0;
}