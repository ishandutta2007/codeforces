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
bool inter(int x1,int y1,int x2,int y2){
    return y1>=x2&&y2>=x1;
}
int main(){
    VPII pp;
    DRI(n);
    REP(i,n){
        DRII(x,y);
        bool err=0;
        REP(j,SZ(pp))
            if(inter(x,x+y-1,pp[j].F,pp[j].S)){err=1;break;}
        if(!err){
            printf("%d %d\n",x,x+y-1);
            pp.PB(MP(x,x+y-1));
        }
        else{
            int lt=0;
            bool suc=0;
            REP(j,SZ(pp)){
                if(pp[j].F-lt-1>=y){
                    suc=1;
                    pp.PB(MP(lt+1,lt+y));
                    printf("%d %d\n",lt+1,lt+y);
                    break;
                }
                lt=pp[j].S;
            }
            if(!suc){
                printf("%d %d\n",pp.back().S+1,pp.back().S+y);
                pp.PB(MP(pp.back().S+1,pp.back().S+y));
            }
        }
        sort(ALL(pp));
    }
    return 0;
}