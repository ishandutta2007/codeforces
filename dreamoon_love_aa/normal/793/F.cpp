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
#define VI vector<int>
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
int from[SIZE],a[SIZE],b[SIZE];
int cnt[SIZE];
LL an[SIZE];
struct data{
    int x,y,id;
    data(int _x=0,int _y=0,int _id=0):x(_x),y(_y),id(_id){}
    bool operator<(const data& b)const{
        return from[x]<from[b.x]||(from[x]==from[b.x]&&y<b.y);
    }
};
vector<data>qq;
VI rope[SIZE];
int n,m,rope_from[SIZE];
PII stk[SIZE];
int sn;
int solve(int x,int y){
    if(SZ(rope[x])==0)return x;
    sn=0;
    REPP(j,x,y+1){
        int sc=rope_from[j];
        if(sc<x)continue;
        while(sn&&sc<=stk[sn-1].S){
            sn--;
            sc=min(sc,stk[sn].F);
        }
        stk[sn++]=MP(sc,j);
    }
    if(!sn||stk[0].F!=x)return x;
    return stk[0].S;
}
int main(){
    DRII(n,m);
    MS1(rope_from);
    REP(i,m){
        DRII(x,y);
        rope[x].PB(y);
        rope_from[y]=x;
    }
    REP(i,n+1)sort(ALL(rope[i]));
    int sqN=sqrt(n+0.1);
    REP(i,n){
        from[i]=i/sqN;
    }
    DRI(Q);
    REP(i,Q){
        DRII(x,y);
        if(y-x<=sqN){
            an[i]=solve(x,y);
        }
        else{
            qq.PB(data(x,y,i));
        }
    }
    sort(ALL(qq));
    int lt=-1;
    REP(i,SZ(qq)){
        int x=qq[i].x,y=qq[i].y;
        int ed=from[x]*sqN+sqN;
        if(from[x]!=lt){
            sn=0;
            REPP(j,ed,y+1){
                int sc=rope_from[j];
                if(sc<ed)continue;
                while(sn&&sc<=stk[sn-1].S){
                    sn--;
                    sc=min(sc,stk[sn].F);
                }
                stk[sn++]=MP(sc,j);
            }
            lt=from[x];
        }
        else REPP(j,max(qq[i-1].y+1,ed),y+1){
            int sc=rope_from[j];
            if(sc<ed)continue;
            while(sn&&sc<=stk[sn-1].S){
                sn--;
                sc=min(sc,stk[sn].F);
            }
            stk[sn++]=MP(sc,j);
        }
        int rr=x;
        REPP(xx,x,ed){
            if(xx>rr)break;
            int it=upper_bound(ALL(rope[xx]),y)-rope[xx].begin();
            if(it){
                it--;
                int j=rope[xx][it];
                if(j>rr)rr=j;
            }
        }
        if(rr<ed)an[qq[i].id]=rr;
        else{
            int it=upper_bound(stk,stk+sn,MP(rr,100000000))-stk;
            if(!it)an[qq[i].id]=rr;
            else an[qq[i].id]=max(rr,stk[it-1].S);
        }
    }
    REP(i,Q)printf("%d\n",an[i]);
    return 0;
}