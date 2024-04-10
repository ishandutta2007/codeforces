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
// template end here
struct data{
    PII pp;
    char c;
    data(){}
    data(const PII& x,char y):pp(x),c(y){}
    bool operator<(const data& b)const{return pp>b.pp;}
}d[3];
char an[200][200];
int main(){
    DRII(x1,y1);
    DRII(x2,y2);
    DRII(x3,y3);
    int sq=x1*y1+x2*y2+x3*y3;
    int w=0;
    while(w*w<sq)w++;
    if(w*w!=sq)return 0*puts("-1");
    if(x1>y1)swap(x1,y1);
    if(x2>y2)swap(x2,y2);
    if(x3>y3)swap(x3,y3);
    d[0]=data(MP(y1,x1),'A');
    d[1]=data(MP(y2,x2),'B');
    d[2]=data(MP(y3,x3),'C');
    sort(d,d+3);
    if(d[0].pp.F!=w)return 0*puts("-1");
    REP(i,d[0].pp.S)REP(j,w)an[i][j]=d[0].c;
    if(d[1].pp.F==w){
        if(d[2].pp.F!=w)return 0*puts("-1");
        REP(i,d[1].pp.S)REP(j,w)an[i+d[0].pp.S][j]=d[1].c;
        REP(i,d[2].pp.S)REP(j,w)an[i+d[0].pp.S+d[1].pp.S][j]=d[2].c;
    }
    else{
        if((d[1].pp.F!=w-d[0].pp.S&&(d[1].pp.S!=w-d[0].pp.S))
         ||(d[2].pp.F!=w-d[0].pp.S&&(d[2].pp.S!=w-d[0].pp.S)))
            return 0*puts("-1");
        int r1=d[1].pp.F+d[1].pp.S-(w-d[0].pp.S);
        REPP(i,d[0].pp.S,w)REP(j,r1)an[i][j]=d[1].c;
        int r2=d[2].pp.F+d[2].pp.S-(w-d[0].pp.S);
        REPP(i,d[0].pp.S,w)REP(j,r2)an[i][j+r1]=d[2].c;
    }
    printf("%d\n",w);
    REP(i,w)puts(an[i]);
    return 0;
}