#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout<<i<<" "<<j<<endl;
#define DB4(i,j,k,l)  if(debug) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
#define RI(i)       scanf("%d",&i)
#define RII(i,j)    scanf("%d%d",&i,&j)
#define RIII(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define RL(i)       scanf("%lld",&i)
#define RLL(i,j)    scanf("%lld%lld",&i,&j)
#define RLLL(i,j,k) scanf("%lld%lld%lld",&i,&j,&k)
///---------------------------
#define MAX 20
#define INF 0x3f3f3f3f
#define debug 1

int main(){
	LL n , m , k;
	char s[20];
	while(~RLLL(n , m , k)){
		LL q , tmp;
		RL(q);
		priority_queue<LL , vector<LL> , greater<LL> > a , b;
		REP(i , q){
			scanf("%lld %s" , &tmp , s);
			if(s[0] == 'U') a.push(tmp);
			else b.push(tmp);
		}
		PLL ans = mp(0 , 0);
		REP(i , n){
			if(a.empty())break;
			ans.A++;
			ans.B += a.top();
			a.pop();
		}
		REP(i , m){
			if(b.empty())break;
			ans.A++;
			ans.B += b.top();
			b.pop();	
		}
		REP(i , k){
			if(a.empty() && b.empty())break;
			LL tmpa = a.size() ? a.top() : -1;
			LL tmpb = b.size() ? b.top() : -1;
			ans.A++;
			if(tmpa == -1) ans.B += tmpb , b.pop();
			else if(tmpb == -1) ans.B += tmpa , a.pop();
			else if(tmpa > tmpb)ans.B += tmpb , b.pop();
			else  ans.B += tmpa , a.pop();
		}
		printf("%lld %lld\n",ans.A , ans.B);

	}
    return 0;
}