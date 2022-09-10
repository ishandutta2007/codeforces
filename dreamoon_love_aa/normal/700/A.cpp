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
    DRII(n,l);
    DRIII(v1,v2,k);
    double ll=l*1./v2,rr=l*1./v1;
    REP(tt,100){
        double mm=(ll+rr)*0.5;
        double need=(l-v1*mm)/(v2-v1);
        if(need<=0)rr=mm;
        else{
            int r=n;
            double pos=0,now=0;
            bool err=0;
            while(r>0&&now<=mm){
                r-=k;
                if(pos+need*v2>l){err=1;break;}
                pos+=need*v2;
                now+=need;
                double add=(pos-now*v1)/(v1+v2);
                now+=add;
                pos-=v2*add;
            }
            if(err||r>0)ll=mm;
            else rr=mm;
        }
    }
    printf("%.12f\n",(ll+rr)*0.5);
    return 0;
}