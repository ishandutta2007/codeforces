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
#define X first
#define F first
#define S second
#define Y second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const double PI=acos(-1);
PII p[SIZE];
PII O;
double R;
double sqr(double x){return x*x;}
vector<pair<double,double> >gg;
int main(){
    RII(O.X,O.Y);
    DRII(v,T);
    DRI(n);
    R=(LL)v*T;
    REP(i,n){
        DRIII(x,y,r);
        x-=O.X;
        y-=O.Y;
        if(sqr(x)+sqr(y)<=sqr(r))return 0*puts("1.00000000");
        if(sqr(x)+sqr(y)-sqr(r)<=sqr(R)||R>3e9){
            double mm=atan2(y,x);
            double aa=asin(r/(sqrt(sqr(x)+sqr(y))));
            double ll=mm-aa;
            double rr=mm+aa;
            while(rr>0){
                ll-=2*PI;
                rr-=2*PI;
            }
            while(rr<0){
                ll+=2*PI;
                rr+=2*PI;
            }
            gg.PB(MP(max(0.,ll),rr));
            ll+=2*PI;
            rr+=2*PI;
            if(ll<2*PI){
                gg.PB(MP(ll,min(rr,2*PI)));
            }
        }
        else if(sqr(R+r)>sqr(x)+sqr(y)){
            double mm=atan2(y,x);
            double a=R;
            double b=sqrt(sqr(x)+sqr(y));
            double c=r;
            double aa=acos(((double)sqr(R)+sqr(x)+sqr(y)-sqr(r))/(2*a*b));
            
            double ll=mm-aa;
            double rr=mm+aa;
            while(rr>0){
                ll-=2*PI;
                rr-=2*PI;
            }
            while(rr<0){
                ll+=2*PI;
                rr+=2*PI;
            }
            gg.PB(MP(max(0.,ll),rr));
            ll+=2*PI;
            rr+=2*PI;
            if(ll<2*PI){
                gg.PB(MP(ll,min(rr,2*PI)));
            }
        }
    }
    sort(ALL(gg));
    double now=0;
    double an=0;
    REP(i,SZ(gg)){
        //printf("%.f %.f\n",gg[i].F,gg[i].S);
        if(gg[i].F>now)an+=gg[i].F-now;
        now=max(now,gg[i].S);
    }
    an+=2*PI-now;
    an=2*PI-an;
    printf("%.12f\n",an/PI*0.5);
    return 0;
}