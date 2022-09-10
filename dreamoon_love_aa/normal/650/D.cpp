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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;
const int SIZE = 1e6+10;
struct PLL{
    LL first;
    pair<LL,LL> second;
    PLL(LL _x=0,pair<LL,LL> _y=MP(0,0)):first(_x),second(_y){}
};
void ADD(LL& x,LL v,LL mod){
    x=(x+v)%mod;
}
pair<LL,LL>& operator+=(pair<LL,LL> &lhs,const pair<LL,LL> &rhs){
    ADD(lhs.F,rhs.F,MOD1);
    ADD(lhs.S,rhs.S,MOD2);
}
pair<LL,LL>& operator*=(pair<LL,LL> &lhs,const pair<LL,LL> &rhs){
    lhs.F=lhs.F*rhs.F%MOD1;
    lhs.S=lhs.S*rhs.S%MOD2;
}
pair<LL,LL> operator+(const pair<LL,LL> &lhs,const pair<LL,LL> &rhs){
    LL v1=lhs.F;
    LL v2=lhs.S;
    ADD(v1,rhs.F,MOD1);
    ADD(v2,rhs.S,MOD2);
    return MP(v1,v2);
}
int h[SIZE];
VPII qq[SIZE];
int d[SIZE],dn;
PLL MPP(LL x,pair<LL,LL> y){
    return PLL(x,y);
}
PLL mid[SIZE];
PLL normal_answer;
PLL BIT[SIZE];
int pos[SIZE];
PLL ins(int x,int v,pair<LL,LL> v2){
    for(;x<SIZE;x+=x&-x){
        if(BIT[x].F<v)BIT[x]=MPP(v,v2);
        else if(BIT[x].F==v)BIT[x].S+=v2;
    }
}
PLL q(int x){
    PLL res=MPP(0,MP(1,1));
    for(;x;x-=x&-x){
        if(BIT[x].F>res.F){
            res=BIT[x];
        }
        else if(BIT[x].F==res.F){
            res.S+=BIT[x].S;
        }
    }
    if(res.F==0)res.S=MP(1,1);
    return res;
}
int tmp_an[SIZE];
int main(){
    DRII(n,m);
    if(n==1){
        REP(i,m)puts("1");
        return 0;
    }
    REP(i,n){
        RI(h[i+1]);
        d[dn++]=h[i+1];
    }
    REP(i,m){
        DRII(x,v);
        pos[i]=x;
        qq[x].PB(MP(v,i));
        d[dn++]=v;
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REPP(i,1,n+1)h[i]=lower_bound(d,d+dn,h[i])-d+1;
    REPP(i,1,n+1){
        REP(j,SZ(qq[i])){
            qq[i][j].F=lower_bound(d,d+dn,qq[i][j].F)-d+1;
        }
    }
    REPP(i,1,n+1){
        PLL res=q(h[i]-1);
        REP(j,SZ(qq[i])){
            tmp_an[qq[i][j].S]=q(qq[i][j].F-1).F+1;
        }
        res.F++;
        if(normal_answer.F<res.F){
            normal_answer=res;
        }
        else if(normal_answer.F==res.F){
            normal_answer.S+=res.S;
        }
        mid[i]=res;
        ins(h[i],res.F,res.S);
    }
    REP(i,SIZE)BIT[i]=PLL();
    for(int i=n;i>0;i--){
        PLL res=q(dn-h[i]);
        REP(j,SZ(qq[i])){
            tmp_an[qq[i][j].S]+=q(dn-qq[i][j].F).F;
        }
        mid[i].F+=res.F;
        mid[i].S*=res.S;
        res.F++;
        ins(dn+1-h[i],res.F,res.S);
    }
    REP(i,m){
        if(tmp_an[i]>=normal_answer.F)printf("%d\n",tmp_an[i]);
        else{
            if(mid[pos[i]].F==normal_answer.F
            && mid[pos[i]].S==normal_answer.S)printf("%d\n",(int)normal_answer.F-1);
            else printf("%d\n",normal_answer.F);
        }
    }
    return 0;
}