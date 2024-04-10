#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> PII;
typedef long long int LL;
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
#define MAX 200000
//#define INF 0x3f3f3f3f
#define debug 1
#define MOD 100000000000000LL
#define INF 1000000000000000LL
#define LIM 1000000000000LL
typedef pair<LL,LL> PLL;
PLL x[MAX];
int main(){

    LL t;
    while(~RL(t)){
        LL big = INF , sml = -INF;
        REP(i,t){
            RLL(x[i].A , x[i].B);
        }
        REP(i,t){
            PLL now;
            now.A = big;
            now.B = sml;
            if(x[i].B == 1)now.B = max(now.B , 1900LL);
            else if(x[i].B == 2)now.A = min(now.A , 1899LL);
            big = now.A + x[i].A;
            sml = now.B + x[i].A;
//            cout<<big<<"  " <<sml<< endl;
        }
//        DBGG(big , "");
//        DBGG(LIM , "");
        if(big < sml)puts("Impossible");
        else if(big >= LIM)puts("Infinity");
        else printf("%I64d\n",big);
    }
    return 0;
}