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
int x[SIZE],y[SIZE];
PII ll[12],rr[12],uu[12],dd[12];
int K;
VPII pp,pp2;
LL an;
void f(int a,int b,int c,int d){
    set<int>H;
    REP(i,a)H.insert(ll[i].S);
    if(SZ(H)>K)return;
    REP(i,b)H.insert(rr[i].S);
    if(SZ(H)>K)return;
    REP(i,c)H.insert(uu[i].S);
    if(SZ(H)>K)return;
    REP(i,d)H.insert(dd[i].S);
    if(SZ(H)>K)return;
    an=min(an,(max(1LL,(rr[b].F-ll[a].F+1LL)/2))*max(1LL,((dd[d].F-uu[c].F+1LL)/2)));
}
int main(){
    an=1e18;
    DRII(n,k);
    K=k;
    REP(i,n){
        DRII(a,b);
        x[i]=a;y[i]=b;
        RII(a,b);
        x[i]+=a;y[i]+=b;
        pp.PB(MP(x[i],i));
        pp2.PB(MP(y[i],i));
    }
    sort(ALL(pp));
    sort(ALL(pp2));
    REP(i,k+1){
        ll[i]=pp[i];
        rr[i]=pp[n-1-i];
        uu[i]=pp2[i];
        dd[i]=pp2[n-1-i];
    }
    REP(a,k+1)
        REP(b,k+1)
            REP(c,k+1){
                REP(d,k+1)f(a,b,c,d);
            }
    cout<<an<<endl;
    return 0;
}