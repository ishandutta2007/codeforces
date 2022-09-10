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

int main(){
    DRIII(d,n,m);
    if(n>=d)return 0*puts("0");
    VPII pp;
    REP(i,m){
        DRII(x,y);
        pp.PB(MP(x,y));
    }
    sort(ALL(pp));
    pp.PB(MP(d,0));
    int lt=0;
    REP(i,m+1){
        if(pp[i].F-lt>n)return 0*puts("-1");
        lt=pp[i].F;
    }
    int now=n;
    LL an=0;
    int it_r=0;
    int it_l=0;
    set<PII>H;
    while(pp[it_r].F<=now){
        H.insert(MP(pp[it_r].S,it_r));
        it_r++;
    }
    while(now<d){
        int sm=H.begin()->S;
        int go=min(pp[sm].F-(now-n),pp[it_r].F-now);
        an+=go*(LL)pp[sm].S;
        now+=go;
        if(now>=d)break;
        while(pp[it_r].F<=now){
            H.insert(MP(pp[it_r].S,it_r));
            it_r++;
        }
        while(pp[it_l].F<=now-n){
            H.erase(MP(pp[it_l].S,it_l));
            it_l++;
        }
    }
    cout<<an;
    return 0;
}