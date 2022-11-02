#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair< LL, LL> PII;
#define REP(i,j) for(LL i=0;i<j;i++)
#define REPNM(i,j,k) for(LL i=j;i<k;i++)
#define RREP(i,j,k) for(LL i=j;i>=k;i--)
#define MEM(i,j) memset(i,j,sizeof i)
#define WHILE(n) while(~scanf("%I64d",&n))
#define WHILE_(n) while(~scanf("%I64d",&n) && n)
#define WHILENM(n,m) while(~scanf("%I64d%I64d",&n,&m))
#define WHILENM_(n,m) while(~scanf("%I64d%I64d",&n,&m) && (n || m) )
#define pb push_back
#define mp make_pair
#define A first
#define B second
#define AC 53LL
#define AMOD 1000000079LL
#define debug 0
#define DB() if(debug)
#define RI(i) scanf("%I64d",&i)

/// ----------- default code ----------------
#define MAX 200500
#define INF 100050000000LL
LL len , timelim;
LL gas[MAX];
PII car[MAX];
LL n , gn , ans;
LL reach(LL id , LL dis){
    if(id < dis)return -1;
    LL tim = dis*2;
    LL gg = id - dis;
    if(gg >= dis)tim -= dis;
    else tim -= gg;
//    DB()printf("ID = %I64d dis = %I64d  tim = %I64d\n",id , dis , tim);
    return tim;
}
LL solve(LL y){
    LL now = 0 , to;
    LL sumT = 0;
    REP(i,gn+1){
        to = gas[i];
        if(to > gas[gn])continue;
        LL qw = reach(y , to-now);
        if(qw == -1)return 0;
        else sumT += qw;
        if(sumT > timelim)return 0;
        now = to;
    }
//    if(sumT <= timelim)
//        printf("good id = %I64d spend %I64d times\n",y , sumT);
    if(sumT <= timelim)return 1;
    return 0;
}
int main()
{
    WHILE(n){
        RI(gn) , RI(len) , RI(timelim);
        REP(i,n) RI(car[i].A) , RI(car[i].B);
        REP(i,gn) RI(gas[i]);
        sort(gas,gas+gn);
//        REPNM(i,1,gn)gas[i] += gas[i-1];
        gas[gn] = len;
        ans = INF;
        LL f = 0 , b = INF;
        while(b-f > 1){
            LL m = (b+f)/2;
            if(solve(m))b = m;
            else f = m;
//            int a;cin>>a;
        }
        REP(i,n)
            if(car[i].B >= b) ans = min(ans , car[i].A);
        if(ans == INF) puts("-1");
        else printf("%I64d\n",ans);
    }
    return 0;
}