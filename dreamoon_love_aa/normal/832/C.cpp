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
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
VPII rr,ll;
int cc[2][SIZE];
int main(){
    double an;
    DRII(n,s);
    REP(i,n){
        DRII(x,v);
        DRI(ty);
        if(ty==2)rr.PB(MP(x,v));
        else ll.PB(MP(x,v));
    }
    sort(ALL(ll));
    sort(ALL(rr));
    if(rr.back().F<ll[0].F){
        double r_normal=1e9,r_fast=1e9;
        REP(i,SZ(rr)){
            mii(r_normal,(1e6-rr[i].F)/rr[i].S);
            mii(r_fast,(1e6-rr[i].F)/(rr[i].S+s));
        }
        double l_normal=1e9,l_fast=1e9;
        REP(i,SZ(ll)){
            mii(l_normal,ll[i].F*1./ll[i].S);
            mii(l_fast,ll[i].F*1./(ll[i].S+s));

        }
        an=min(max(r_normal,l_fast),max(r_fast,l_normal));
    }
    else{
        double _ll=0,_rr=1e6;

        REP(ker,50){
            double mm=(_ll+_rr)*0.5;
            MS0(cc);
            REP(i,SZ(ll)){
                double oo=ll[i].F*1./ll[i].S;
                if(oo<=mm)cc[0][1]++;
                else{
                    if(ll[i].F*1./(ll[i].S+s)<=mm){
                        cc[0][ll[i].F]++;
                        double need_time=(ll[i].F-mm*ll[i].S)/s;
                        cc[0][min(ll[i].F+(LL)ceil((mm-need_time)*(s-ll[i].S)+1e-12),1000000LL)]--;
                    }
                }
            }
            REP(i,SZ(rr)){
                double oo=(1e6-rr[i].F)/rr[i].S;
                if(oo<=mm)cc[1][1]++;
                else{
                    if((1e6-rr[i].F)/(rr[i].S+s)<=mm){
                        cc[1][rr[i].F+1]--;
                        double need_time=(1e6-rr[i].F-mm*rr[i].S)/s;
                        cc[1][max(rr[i].F-(LL)floor((mm-need_time)*(s-rr[i].S)-1e-12),1LL)]++;
                    }
                }
            }
            bool suc=0;
            REPP(j,1,SIZE){
                REP(i,2){
                    cc[i][j]+=cc[i][j-1];
                }
                if(cc[0][j]&&cc[1][j])suc=1;
                if(suc)break;
            }
            if(suc)_rr=mm;
            else _ll=mm;
        }
        an=(_ll+_rr)*0.5;
    }
    printf("%.15f\n",an);
    return 0;
}