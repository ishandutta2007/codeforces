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
#define MAX 
#define INF 0x3f3f3f3f
#define debug 1

void Solve(){}

map<LL , LL> cc , nt;

LL Find(LL now){
	if(cc.find(now) != cc.end()) return cc[now];
	auto it = nt.upper_bound(now);
	it--;
	// DBGG(it->A , it->B);
	LL tmp = (now - (it->A - 1)) % it->B;
	// DBGG("tmp = " , tmp);
	if(!tmp) tmp += it->B;
	return Find(tmp); 
}
int main(){
	LL n;
	RL(n);
	LL now = 1;
	REP(i , n){
		LL q , w , e;
		RL(q);
		if(q == 1){
			RL(w);
			cc[now ++] = w;
		}
		else {
			RLL(w , e);
			nt[now] = w;
			now += w * e;
		}
		// DBGG("now = " , now);
	}
	LL q , w;
	RI(q);
	REP(i , q){
		RL(w);
		cout << Find(w) << " " ;
	}
	cout << endl;
    return 0;
}