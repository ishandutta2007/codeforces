#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define AS assert
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f
#define debug 1
LL a , b , d1 , d2;
int F(LL q , LL w , LL e){
    // LL qq = q , ww = w , ee = e;

    LL sum = q + w + e;
    // DB4(q , w , e , sum);
    if((b - sum) % 3 != 0) return 0;
    sum = (b - sum) / 3;
    q += sum;
    w += sum;
    e += sum;
    
    if(q < 0 || w < 0 || e < 0) return 0;
    LL mm = max(q , max(w , e));
    sum = mm - q + mm - w + mm - e;
    if(a - b < sum)return 0;
    if((a - b - sum) % 3 != 0) return 0;
    // DB4(qq , ww , ee , sum);
    return 1;
}
int main(){
    int n;
    RI(n);
    while(n--){
        RLL(a , b);
        RLL(d1 , d2);
        int ok = 0;
        ok = max(ok , F(0 , d1 , d1 + d2));
        ok = max(ok , F(0 , d1 , d1 - d2));
        ok = max(ok , F(0 , -d1 , -d1 - d2));
        ok = max(ok , F(0 , -d1 , -d1 + d2));
        if(ok) puts("yes");
        else puts("no");
    }
    return 0;
}