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
const double PI=acos(-1);
int main(){
    DRIII(n,r,v);
    while(n--){
        DRII(s,f);
        int d=f-s;
        double ll=0,rr=d;
        REP(k,100){
            double mm=(ll+rr)*0.5;
            double angle=mm/r;
            angle-=floor(angle/(2*PI))*2*PI;
            while(angle<0)angle+=2*PI;
            while(angle>=2*PI)angle-=2*PI;
            if(angle>=PI)angle=2*PI-angle;
            double len=mm+r*sin(angle*0.5)*2;
            if(len>d)rr=mm;
            else ll=mm;
        }
        printf("%.12f\n",(ll+rr)*0.5/v);
    }
    return 0;
}