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
const int SIZE = 1e6+10;
VI A,B;
LL A_sum,B_sum;
void read(VI &x){
    DRI(n);
    REP(i,n){
        DRI(y);
        x.PB(y);
    }
}
VPII res;
LL mi;
bool mii(LL &x,LL v){
    if(v<x){
        x=v;
        return 1;
    }
    return 0;
}
struct data{
    LL v;
    int x,y;
    data(LL _v=0,int _x=0,int _y=0):v(_v),x(_x),y(_y){}
    bool operator<(const data& b)const{return v<b.v;}
};
int main(){
    read(A);
    read(B);
    REP(i,SZ(A))A_sum+=A[i];
    REP(i,SZ(B))B_sum+=B[i];
    mi=abs(A_sum-B_sum);
    REP(i,SZ(A))REP(j,SZ(B)){
        if(mii(mi,abs((A_sum-A[i]+B[j])-(B_sum-B[j]+A[i])))){
            res.clear();
            res.PB(MP(i+1,j+1));
        }
    }
    vector<data>AA,BB;
    REP(i,SZ(A))REP(j,i){
        AA.PB(data(A[j]+A[i],j,i));
    }
    REP(i,SZ(B))REP(j,i){
        BB.PB(data(B[j]+B[i],j,i));
    }
    sort(ALL(AA));
    sort(ALL(BB));
    int it=0;
    REP(i,SZ(AA)){
        while(it<SZ(BB)&&A_sum-AA[i].v+BB[it].v<B_sum-BB[it].v+AA[i].v)it++;
        if(it<SZ(BB)&&mii(mi,abs(A_sum-AA[i].v+BB[it].v-(B_sum-BB[it].v+AA[i].v)))){
            res.clear();
            res.PB(MP(AA[i].x+1,BB[it].x+1));
            res.PB(MP(AA[i].y+1,BB[it].y+1));
        }
        if(it&&mii(mi,abs(A_sum-AA[i].v+BB[it-1].v-(B_sum-BB[it-1].v+AA[i].v)))){
            res.clear();
            res.PB(MP(AA[i].x+1,BB[it-1].x+1));
            res.PB(MP(AA[i].y+1,BB[it-1].y+1));
        }
    }
    printf("%I64d\n",mi);
    printf("%d\n",SZ(res));
    REP(i,SZ(res))printf("%d %d\n",res[i].F,res[i].S);
    return 0;
}