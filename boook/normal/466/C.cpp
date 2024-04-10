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
#define MAX 500900
#define INF 0x3f3f3f3f
#define debug 1
LL x[MAX];
LL pre[MAX];
int main(){
    LL n;
    while(~RL(n)){
        LL sum = 0;
        REP(i , n) RL(x[i]) , sum += x[i];
        if(sum % 3 != 0 || n <= 2) puts("0");
        else {
            LL goal = sum / 3;
            LL ttmp = 0;
            MEM(pre , 0);

            REP(i , n - 1){
                ttmp += x[i];
                if(ttmp == goal) pre[i] = 1;
                if(i != 0) pre[i] += pre[i - 1];
            }

            ttmp = 0;
            LL ans = 0;
            RREP(i , n - 1 , 2){
                ttmp += x[i];
                if(ttmp == goal) ans += pre[i - 2];
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}