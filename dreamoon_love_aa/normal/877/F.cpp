#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef int64_t LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
int t[SIZE],a[SIZE],from[SIZE],dn,N,K;
LL d[SIZE],v[SIZE],p[SIZE];
int lp[SIZE],rp[SIZE];
struct data{
    int x,y,id;
    bool operator<(const data& b)const{
        if(from[x]==from[b.x])
            return y<b.y;
        return from[x]<from[b.x];
    }

}qq[SIZE];
void pre(){
    REP(i,N+1){
        v[i]=lower_bound(d,d+dn,p[i])-d;
    }
    MS1(lp);
    MS1(rp);
    REP(i,dn){
        int it=lower_bound(d,d+dn,d[i]-K)-d;
        if(it<N&&d[i]-K==d[it])lp[i]=it;
        it=lower_bound(d,d+dn,d[i]+K)-d;
        if(it<N&&d[i]+K==d[it])rp[i]=it;
    }
}
LL an[SIZE];
LL res;
int cnt[SIZE];
void edit_r(int x,int ty){
    if(ty<0)cnt[x]+=ty;
    if(lp[x]!=-1)res+=cnt[lp[x]]*ty;
    if(ty>0)cnt[x]+=ty;
}
void edit_l(int x,int ty){
    if(ty<0)cnt[x]+=ty;
    if(rp[x]!=-1)res+=cnt[rp[x]]*ty;
    if(ty>0)cnt[x]+=ty;
}
int main(){
    RII(N,K);
    int sqn=sqrt(N+0.1);
    REP(i,N)RI(t[i]);
    REP(i,N)RI(a[i]);
    LL now=0;
    REP(i,N){
        from[i]=i/sqn;
        if(t[i]==1)now+=a[i];
        else now-=a[i];
        p[i+1]=now;
    }
    REP(i,N+1)d[i]=p[i];
    sort(d,d+N+1);
    dn=unique(d,d+N+1)-d;
    pre();
    DRI(Q);
    REP(i,Q){
        RII(qq[i].x,qq[i].y);
        qq[i].x--;
        qq[i].id=i;
    }
    sort(qq,qq+Q);
    int ll=qq[0].x,rr=qq[0].x-1;
    REP(i,Q){
        while(rr<qq[i].y)edit_r(v[++rr],1);
        while(ll>qq[i].x)edit_l(v[--ll],1);
        while(rr>qq[i].y)edit_r(v[rr--],-1);
        while(ll<qq[i].x)edit_l(v[ll++],-1);
        an[qq[i].id]=res;
    }
    REP(i,Q)printf("%lld\n",an[i]);
    return 0;
}