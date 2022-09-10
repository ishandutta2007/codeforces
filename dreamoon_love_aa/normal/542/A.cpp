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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MAX = 1e9+7;
const int SIZE = 1e6+10;
// template end here

PII BIT[SIZE];
void ins(int x,PII v){
    for(;x;x-=x&-x)BIT[x]=min(BIT[x],v);
}
PII qq(int x){
    PII res=MP(MAX,0);
    for(;x<SIZE;x+=x&-x)res=min(res,BIT[x]);
    return res;
}
struct data{
    int x,y,v,ty,id;
    data(int _x=0,int _y=0,int _v=0,int _ty=0,int _id=0):x(_x),y(_y),v(_v),ty(_ty),id(_id){}
    bool operator<(const data& b)const{
        return y<b.y||(y==b.y&&ty<b.ty);
    }
}video[SIZE],TV[SIZE],r[SIZE];
int rn;
int d[SIZE];
int dn;
int get(int x){return lower_bound(d,d+dn,x)-d+1;}
LL ma;
int an[2];
void rev(int &x){
    x=1000000000-x;
}
int main(){
    DRII(n,m);
    //1
    REP(i,n){
        DRII(x,y);
        d[dn++]=y;
        video[i]=data(x,y,i+1,0,i+1);
    }
    REP(i,m){
        RIII(TV[i].x,TV[i].y,TV[i].v);
        TV[i].ty=1;
        TV[i].id=i+1;
        d[dn++]=TV[i].y;
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REP(i,SIZE)BIT[i]=MP(MAX,-1);
    REP(i,n){
        ins(get(video[i].y),MP(video[i].x,video[i].v));
    }
    REP(i,m){
        PII res=qq(get(TV[i].y));
        if((LL)(TV[i].y-max(TV[i].x,res.F))*TV[i].v>ma){
            ma=(LL)(TV[i].y-max(TV[i].x,res.F))*TV[i].v;
            an[0]=res.S;
            an[1]=i+1;
        }
    }

    //2
    dn=0;
    REP(i,n){
        rev(video[i].x);
        rev(video[i].y);
        swap(video[i].x,video[i].y);
        d[dn++]=video[i].y;
    }
    REP(i,m){
        rev(TV[i].x);
        rev(TV[i].y);
        swap(TV[i].x,TV[i].y);
        d[dn++]=TV[i].y;
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REP(i,SIZE)BIT[i]=MP(MAX,-1);
    REP(i,n){
        ins(get(video[i].y),MP(video[i].x,video[i].v));
    }
    REP(i,m){
        PII res=qq(get(TV[i].y));
        if((LL)(TV[i].y-max(TV[i].x,res.F))*TV[i].v>ma){
            ma=(LL)(TV[i].y-max(TV[i].x,res.F))*TV[i].v;
            an[0]=res.S;
            an[1]=i+1;
        }
    }
    //3
    dn=0;
    REP(i,n){
        r[rn++]=video[i];
        d[dn++]=video[i].x;
        d[dn++]=video[i].y;
    }
    REP(i,m){
        r[rn++]=TV[i];
        d[dn++]=TV[i].x;
        d[dn++]=TV[i].y;
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    sort(r,r+rn);
    REP(i,SIZE)BIT[i]=MP(MAX,-1);
    REP(i,rn){
        if(r[i].ty==0){
            //printf("[%d]\n",get(r[i].x));
            ins(get(r[i].x),MP(r[i].x-r[i].y,r[i].v));
        }
        else{
            PII res=qq(get(r[i].x));
            //printf("%d(%d,%d)\n",get(r[i].x),res.F,res.S);
            if(-1LL*res.F*r[i].v>ma){
                ma=-1LL*res.F*r[i].v;
                an[0]=res.S;
                an[1]=r[i].id;
            }
        }
    }
    cout<<ma<<endl;
    if(ma>0)printf("%d %d\n",an[0],an[1]);
    return 0;
}