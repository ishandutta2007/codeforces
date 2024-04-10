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
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int MUL1 = 137;
const int MUL2 = 131;
const int SIZE = 2e5+10;
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
char s[SIZE];
int sn,tn;
PLL dp[SIZE];
PLL inv[SIZE],pwr[SIZE];
bool same(int st1,int st2,int len){
    return ((dp[st1+len-1].F-dp[st1-1].F)*inv[st1].F-(dp[st2+len-1].F-dp[st2-1].F)*inv[st2].F)%MOD==0
       &&  ((dp[st1+len-1].S-dp[st1-1].S)*inv[st1].S-(dp[st2+len-1].S-dp[st2-1].S)*inv[st2].S)%MOD==0;
}
int compare_substring(int st1,int st2,int len){
    int ll=0,rr=len;
    while(ll<rr){
        int mm=(ll+rr+1)/2;
        if(same(st1,st2,mm))ll=mm;
        else rr=mm-1;
    }
    if(ll==len)return 0;
    if(s[st1+ll]<s[st2+ll])return 1;
    return -1;
}
int compare2(PII d[][2]){
    int it1=0,it2=0;
    while(it1<2&&it2<2){
        if(d[0][it1].F==d[0][it1].S){
            it1++;
            continue;
        }
        if(d[1][it2].F==d[1][it2].S){
            it2++;
            continue;
        }
        int mi=min(d[0][it1].S-d[0][it1].F,d[1][it2].S-d[1][it2].F);
        int ret=compare_substring(d[0][it1].F,d[1][it2].F,mi);
        if(ret>0)return 1;
        if(ret<0)return -1;
        d[0][it1].F+=mi;
        d[1][it2].F+=mi;
    }
    return 0;
}
bool compare(int x,int y){
    x++;y++;
    if(x<y){
        PII d[2][2];
        d[0][0]=MP(sn+1,sn+tn+1);
        d[0][1]=MP(x,y);
        d[1][0]=MP(x,y);
        d[1][1]=MP(sn+1,sn+tn+1);
        int ret=compare2(d);
        return ret>=0;
    }
    else{
        swap(x,y);
        PII d[2][2];
        d[1][0]=MP(sn+1,sn+tn+1);
        d[1][1]=MP(x,y);
        d[0][0]=MP(x,y);
        d[0][1]=MP(sn+1,sn+tn+1);
        int ret=compare2(d);
        return ret>0;
    }
}
void build(){
    int stn=sn+tn;
    pwr[0]=inv[0]=MP(1,1);
    REPP(i,1,stn+1){
        pwr[i]=MP(pwr[i-1].F*MUL1%MOD,pwr[i-1].S*MUL2%MOD);
    }
    inv[1]=MP(mypow(MUL1,MOD-2),mypow(MUL2,MOD-2));
    REPP(i,2,stn+1){
        inv[i]=MP(inv[i-1].F*inv[1].F%MOD,inv[i-1].S*inv[1].S%MOD);
    }
    REPP(i,1,stn+1){
        dp[i]=MP((dp[i-1].F+pwr[i].F*s[i])%MOD,(dp[i-1].S+pwr[i].S*s[i])%MOD);
    }
}
int sorted_list[SIZE];
int ord[SIZE];
int an[SIZE];
VI qq[SIZE];
const int BB=250;
int rmq_mi[17][SIZE],to[SIZE],now_mod;
int l[SIZE],r[SIZE],xx[SIZE],yy[SIZE];
void build_rmq(int mod,int r){
    now_mod=mod;
    int dn=0;
    while(r<=sn){
        rmq_mi[0][dn++]=ord[r];
        r+=mod;
    }
    REPP(i,1,17){
        for(int j=0;j+(1<<i)<=dn;j++){
            rmq_mi[i][j]=min(rmq_mi[i-1][j],rmq_mi[i-1][j+(1<<(i-1))]);
        }
    }
}
int qq_rmq(int L,int R){
    int n=R-L+1;
    int lv=to[n];
    return min(rmq_mi[lv][L],rmq_mi[lv][R-(1<<lv)+1]);
}
void solve(int mod){
    if(SZ(qq[mod])==0)return;
    if(mod==1||mod>=BB){
        if(now_mod!=1)build_rmq(1,0);
        REP(i,SZ(qq[mod])){
            int id=qq[mod][i];
            int now_l=xx[id],now_r=yy[id];
            while(now_r<l[id]){now_l+=mod;now_r+=mod;}
            while(now_l<=r[id]){
                an[id]=min(an[id],qq_rmq(max(l[id],now_l),min(r[id],now_r)));
                now_l+=mod;
                now_r+=mod;
            }
        }
    }
    else{
        REP(r2,mod){
            build_rmq(mod,r2);
            REP(i,SZ(qq[mod])){
                int id=qq[mod][i];
                if(xx[id]>r2||yy[id]<r2)continue;
                int ll=l[id]/mod*mod+r2;
                while(ll<l[id])ll+=mod;
                int rr=r[id]/mod*mod+r2;
                while(rr>r[id])rr-=mod;
                while(rr+mod<=r[id])rr+=mod;
//                if(mod==4&&r2==1)printf("[%d,%d]\n",ll,rr);
                if(ll<=rr)an[id]=min(an[id],qq_rmq(ll/mod,rr/mod));
            }
        }
    }
}
int main(){
    REP(i,17){
        REPP(j,1,SIZE){
            if((1<<i)<=j)to[j]=i;
        }
    }
    RS(s+1);
    sn=LEN(s+1);
    RS(s+1+sn);
    tn=LEN(s+1+sn);
    DRI(q);
    build();
    REP(i,sn+1)sorted_list[i]=i;
    sort(sorted_list,sorted_list+sn+1,compare);
    REP(i,sn+1)ord[sorted_list[i]]=i;
    REP(i,q){
        an[i]=MOD;
        RII(l[i],r[i]);
        DRI(K);
        qq[K].PB(i);
        RII(xx[i],yy[i]);
    }
    REPP(i,2,sn+1){solve(i);}
    solve(1);
    REP(i,q){
        if(an[i]==MOD)puts("-1");
        else printf("%d\n",sorted_list[an[i]]);
    }
    return 0;
}