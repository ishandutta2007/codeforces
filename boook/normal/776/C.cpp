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
#define MAX 100090
#define INF 0x3f3f3f3f
#define debug 1
#define LIM 1000000000000000LL // 15

vector<LL> v;
set<LL> vs;
map<LL , LL> cc;
LL xc[MAX] , x[MAX];
int main(){
    LL n , k;
    RLL(n , k);
    REPNM(i , 1 , n + 1) RL(xc[i]);
    REPNM(i , 1 , n + 1) x[i] = x[i - 1] + xc[i];

    LL tmp = 1;
    while(tmp < LIM){
        if(vs.find(tmp) != vs.end()) break;
        // DBGG("now = " , tmp);
        v.pb(tmp);
        vs.insert(tmp);
        tmp = tmp * k;
    }
    LL ans = 0;
    cc[0] ++;
    REPNM(i , 1 , n + 1){
        REP(j , v.size()){
            LL wnt = x[i] - v[j];
            // DBGG(i , wnt);
            if(cc.find(wnt) != cc.end()) ans += cc[wnt];
        }
        // DBGG("ans = " , ans);
        cc[x[i]] ++;
    }
    printf("%lld\n", ans);
    return 0;
}