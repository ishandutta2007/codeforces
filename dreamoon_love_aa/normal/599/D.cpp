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
VPLL an;
void ADD(LL x,LL y){
    an.PB(MP(x,y));
    if(x!=y)an.PB(MP(y,x));
}
LL x;
int main(){
    cin>>x;
    LL now=1;
    while(now*(now+1)*(2*now+1)/6<=x){
        LL base=now*(now+1)*(2*now+1)/6;
        LL ker=now*(now+1)/2;
        if((x-base)%ker==0)ADD(now,now+(x-base)/ker);
        now++;
    }
    sort(ALL(an));
    printf("%d\n",SZ(an));
    REP(i,SZ(an))cout<<an[i].F<<" "<<an[i].S<<endl;
    return 0;
}