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
const int SIZE = 1e6+10;
int d[SIZE][2];
int u[SIZE];
int main(){
    DRI(n);
    vector<pair<PII,int>> pp;
    REP(i,n){
        DRII(x,y);
        d[i][0]=x;
        d[i][1]=y;
        pp.PB(MP(MP(x,i),1));
        pp.PB(MP(MP(y+1,i),-1));
    }
    sort(ALL(pp));
    int now=0;
    set<int>H;
    for(int i=0,j;i<SZ(pp);i=j){
        for(j=i;j<SZ(pp)&&pp[j].F.F==pp[i].F.F;j++){
            now+=pp[j].S;
            if(pp[j].S==1)H.insert(pp[j].F.S);
            else H.erase(pp[j].F.S);
        }
        if(now==1){
            u[*H.begin()]=1;
        }
    }
    REP(i,n)
        if(!u[i])return 0*printf("%d\n",i+1);
    return 0*puts("-1");
}