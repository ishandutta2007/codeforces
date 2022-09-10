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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int main(){
    vector<pair<int,int> >pp;
    DRI(n);
    int s[2]={};
    REP(i,n){
        DRI(x);
        pp.PB(MP(x,1));
        s[0]+=2;
    }
    RI(n);
    REP(i,n){
        DRI(x);
        pp.PB(MP(x,-1));
        s[1]+=2;
    }
    int dif=s[0]-s[1],an=s[0];
    sort(ALL(pp));
    reverse(ALL(pp));

    for(int i=0,j;i<SZ(pp);i=j){
        for(j=i;j<SZ(pp)&&pp[j].F==pp[i].F;j++){
            if(pp[j].S==1)s[0]++;
            else s[1]++;
        }
        if(s[0]-s[1]>=dif){
            dif=s[0]-s[1];
            an=s[0];
        }
    }
    printf("%d:%d\n",an,an-dif);
    return 0;
}