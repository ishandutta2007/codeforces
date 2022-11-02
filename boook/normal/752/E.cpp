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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define debug 1

LL n , m ;
LL x[MAX];

LL FF(LL q , LL w){
    if(q < w)return 0;
    LL ans = 1;
    LL ff = w , bb = w*2-1;
    while(ff*2 <= q){
        ans*=2;
        ff*=2;
        bb*=2;
    }
//    cout<<ff <<"   "<<bb<<endl;
    if(ff <= q && q <= bb)return ans;
    ans += q - bb;
    return ans;
}
LL F(LL y){
    LL sum = 0;
    REP(i,n){
        sum += FF(x[i] , y);
    }
    return (sum >= m);
}
int main(){
//    cout<<FF(200,13)<<endl;
//    cout<<FF(103,13)<<endl;
//    cout<<FF(105,13)<<endl;
//    cout<<FF(201,13)<<endl;
////    cout<<FF(12,6)<<endl;
//    cout<<FF(14,6)<<endl;
    RLL(n , m);
    REP(i,n) RL(x[i]);
    LL f = 0 , b = INF;
    while(b - f > 1){
        LL mid = (f + b)/2;
        if(F(mid)) f = mid;
        else b = mid;
    }
    if(f == 0)printf("-1\n");
    else printf("%I64d\n",f);
//    LL
    return 0;
}