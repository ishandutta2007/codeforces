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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1<<17;
string s[SIZE];
int h[SIZE];
int ma[SIZE*2+100];
VPII stkL[SIZE*2+100],stkR[SIZE*2+100];
void pre(int n){
    REPP(i,2,n+1){
        while(h[i]<min(SZ(s[i-1]),SZ(s[i]))&&s[i-1][h[i]]==s[i][h[i]])h[i]++;
    }
}
int sid;
void pull(int id,int mm_v,int idL=0,int idR=0){
    //if(id*2+1>=SIZE&&id<SIZE)return;
    if(idL==0)idL=id*2;
    if(idR==0)idR=id*2+1;
    //printf("___ %d\n",ma[id]);
    ma[id]=max(ma[idL],ma[idR]);
    //printf("___ %d\n",ma[id]);
    int itR=0,itL=0;
    int num=0;
    while(itR<SZ(stkR[idL])&&stkR[idL][itR].F>=mm_v)num+=stkR[idL][itR++].S;
    while(itL<SZ(stkL[idR])&&stkL[idR][itL].F>=mm_v)num+=stkL[idR][itL++].S;
    ma[id]=max(ma[id],num*mm_v);
    while(itR<SZ(stkR[idL])&&itL<SZ(stkL[idR])){
        if(stkR[idL][itR]>=stkL[idR][itL]){
            num+=stkR[idL][itR].S;
            ma[id]=max(ma[id],num*stkR[idL][itR++].F);
        }
        else{
            num+=stkL[idR][itL].S;
            ma[id]=max(ma[id],num*stkL[idR][itL++].F);
        }
    }
    while(itR<SZ(stkR[idL])){
        num+=stkR[idL][itR].S;
        ma[id]=max(ma[id],num*stkR[idL][itR++].F);
    }
    while(itL<SZ(stkL[idR])){
        num+=stkL[idR][itL].S;
        ma[id]=max(ma[id],num*stkL[idR][itL++].F);
    }

    stkL[id]=stkL[idL];
    stkL[id].resize(SZ(stkL[idL])+SZ(stkL[idR]));
    itL=SZ(stkL[idL]);
    int now_v=min(stkL[idL].back().F,mm_v);
    int it=0;
    int sp_num=0;
    while(it<SZ(stkL[idR])&&stkL[idR][it].F>=now_v){
        sp_num+=stkL[idR][it++].S;
    }
    if(sp_num){
        if(now_v==stkL[idL].back().F){
            stkL[id][SZ(stkL[idL])-1].S+=sp_num;
        }
        else{
            stkL[id][itL++]=MP(now_v,sp_num);
        }
        sp_num=0;
    }
    for(;it<SZ(stkL[idR]);it++)stkL[id][itL++]=stkL[idR][it];
    stkL[id].resize(itL);

    stkR[id]=stkR[idR];
    stkR[id].resize(SZ(stkR[idL])+SZ(stkR[idR]));
    itR=SZ(stkR[idR]);
    now_v=min(stkR[idR].back().F,mm_v);
    it=0;
    while(it<SZ(stkR[idL])&&stkR[idL][it].F>=now_v){
        sp_num+=stkR[idL][it++].S;
    }
    if(sp_num){
        if(now_v==stkR[idR].back().F){
            stkR[id][SZ(stkR[idR])-1].S+=sp_num;
        }
        else{
            stkR[id][itR++]=MP(now_v,sp_num);
        }
        sp_num=0;
    }
    for(;it<SZ(stkR[idL]);it++)stkR[id][itR++]=stkR[idL][it];
    stkR[id].resize(itR);
}
void build(int L,int R,int id){
    int mm=(L+R)/2;
    if(L==R){
        ma[id]=SZ(s[L]);
        stkL[id]=stkR[id]=VPII(1,MP(ma[id],1));
        return;
    }
    build(L,mm,id*2);
    build(mm+1,R,id*2+1);
    pull(id,h[mm+1]);
}
void print(string name,VPII& x){
    printf("[%s:",name.c_str());
    REP(i,SZ(x))printf("(%d,%d)%c",x[i].F,x[i].S,",]"[i==SZ(x)-1]);
    puts("");
}
int qq(int L,int R,int id,int ll,int rr,int rid){
    if(R<ll||L>rr){
        stkL[rid]=stkR[rid]=VPII();
        ma[rid]=0;
        return 0;
    }
    if(L>=ll&&R<=rr){
        stkR[rid]=stkR[id];
        stkL[rid]=stkL[id];
        ma[rid]=ma[id];
        //printf("(%d,%d):%d\n",L,R,ma[id]);
        return ma[id];
    }
    int mm=(L+R)/2;
    if(rr<=mm)return qq(L,mm,id*2,ll,rr,rid);
    if(ll>mm)return qq(mm+1,R,id*2+1,ll,rr,rid);
    int ridL=sid++;
    int ridR=sid++;
    int ret=max(qq(L,mm,id*2,ll,rr,ridL),qq(mm+1,R,id*2+1,ll,rr,ridR));
    //print("stL[ridL]",stkL[ridL]);
    //print("stR[ridL]",stkR[ridL]);
    //print("stL[ridR]",stkL[ridR]);
    //print("stR[ridR]",stkR[ridR]);
    pull(rid,h[mm+1],ridL,ridR);
    ret=max(ret,ma[rid]);
    //printf("{{%d,%d}}",ma[rid],ma[rid]);
    //printf("{%d}(%d,%d):%d\n",h[mm+1],L,R,ret);
    return ret;
}
void edit(int L,int R,int id,int x){
    if(L==R){
        ma[id]=SZ(s[L]);
        stkL[id]=stkR[id]=VPII(1,MP(ma[id],1));
        return;
    }
    int mm=(L+R)/2;
    if(x<=mm)edit(L,mm,id*2,x);
    else edit(mm+1,R,id*2+1,x);
    pull(id,h[mm+1]);
}
void update(int x,int n){
    cin>>s[x];
    REPP(i,max(2,x),min(x+1,n)+1){
        h[i]=0;
        while(h[i]<min(SZ(s[i-1]),SZ(s[i]))&&s[i-1][h[i]]==s[i][h[i]])h[i]++;
    }
    //REPP(i,2,n+1)printf("%d%c",h[i],",\n"[i==n]);
    edit(1,n,1,x);
}
int main(){
    DRII(n,q);
    REPP(i,1,n+1)cin>>s[i];
    pre(n);
    build(1,n,1);
    REP(ker,q){
        DRI(ty);
        if(ty==1){
            DRII(x,y);
            sid=SIZE*2;
            printf("%d\n",qq(1,n,1,x,y,sid++));
        }
        else{
            DRI(x);
            update(x,n);
        }
    }
    return 0;
}