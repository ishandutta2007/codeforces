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
int n,m;
LL an[SIZE];
PII q[SIZE];
VI RU[SIZE],RD[SIZE];
void mii(LL& x,LL v){
    if(x==-1||x>v)x=v;
}
map<PII,int>H;
VI e[SIZE];
PII pp[SIZE];
int id;
int ADD(PII x){
    if(H.count(x))return H[x];
    pp[id]=x;
    return H[x]=id++;
}
void go(int x,int lt,LL t){
    int y=e[x][0];
    if(lt==y){
        if(SZ(e[x])==1)return;
        y=e[x][1];
    }
    //printf("(%d,%d)-(%d,%d)\n",pp[x].F,pp[x].S,pp[y].F,pp[y].S);
    if(pp[x].F+pp[x].S==pp[y].F+pp[y].S){
        int v=pp[x].F+pp[x].S;
        REP(i,SZ(RD[v])){
            int you=RD[v][i];
            mii(an[you],t+abs(pp[x].F-q[you].F));
        }
    }
    else{
        int v=pp[x].F-pp[x].S+m;
        REP(i,SZ(RU[v])){
            int you=RU[v][i];
            mii(an[you],t+abs(pp[x].F-q[you].F));
        }
    }
    go(y,x,t+abs(pp[x].F-pp[y].F));
}
int main(){
    MS1(an);
    int K;
    RIII(n,m,K);
    REP(i,n){
        int x=ADD(MP(i,0));
        int y=-1;
        if(i<=n-m){
            y=ADD(MP(i+m,m));
        }
        else{
            y=ADD(MP(n,n-i));
        }
        e[x].PB(y);
        e[y].PB(x);
        //
        x=ADD(MP(i,m));
        if(i+m<=n){
            y=ADD(MP(i+m,0));
        }
        else{
            y=ADD(MP(n,i+m-n));
        }
        e[x].PB(y);
        e[y].PB(x);
    }
    REPP(i,1,m){
        int x=ADD(MP(0,i));
        int y=-1;
        if(i+n<=m){
            y=ADD(MP(n,i+n));
        }
        else{
            y=ADD(MP(m-i,m));
        }
        e[x].PB(y);
        e[y].PB(x);
        //
        if(i>=n){
            y=ADD(MP(n,i-n));
        }
        else{
            y=ADD(MP(i,0));
        }
        e[x].PB(y);
        e[y].PB(x);
    }
    REP(i,K){
        DRII(x,y);
        q[i]=MP(x,y);
        RD[x+y].PB(i);
        RU[x-y+m].PB(i);
    }
    go(0,0,0);
    REP(i,K)printf("%I64d\n",an[i]);
    return 0;
}