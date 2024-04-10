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
#define MAX 100090
#define INF 0x3f3f3f3f
#define debug 1

void Solve(){}

LL n , x[MAX] , ok;
map<LL , int> cc;
void P(LL now){
	if(!ok) printf("%lld", now) , ok = 1;
	else printf(" %lld", now);
}
LL Pr(LL now){
	auto it = cc.lower_bound(now);
	if(it == cc.begin()) return -1;
	it--;
	return it->A;
}
LL Nxt(LL now){
	auto it = cc.upper_bound(now);
	if(it == cc.end()) return -1;
	return it->A;
}
int main(){
	RL(n);
	REP(i , n) RL(x[i]);
	REP(i , n){
		if(i == 0){
			cc[x[i]] = 8;
		}
		else {
			LL f = Pr(x[i]) , b = Nxt(x[i]);
			// DBGG(f , b);
			if(f == -1) cc[b] |= 2 , P(b);
			else if(b == -1) cc[f] |= 1 , P(f);
			else {
				if(cc[b] & 2) cc[f] |= 1 , P(f);
				else cc[b] |= 2 , P(b);
			}
			if(b != -1 && cc[b] == 3){
				auto it = cc.find(b);
				cc.erase(b);
			}
			if(f != -1 && cc[f] == 3){
				auto it = cc.find(f);
				cc.erase(f);	
			}
			cc[x[i]] = 8;
		}
	}
	puts("");
    return 0;
}