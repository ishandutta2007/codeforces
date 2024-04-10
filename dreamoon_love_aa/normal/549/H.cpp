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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here
void get(double x,double y,double z,double w,double& mi,double& ma){
    mi=1e27;
    ma=-1e27;
    ma=max(ma,y*w);
    ma=max(ma,y*z);
    ma=max(ma,x*w);
    ma=max(ma,x*z);
    mi=min(mi,y*w);
    mi=min(mi,y*z);
    mi=min(mi,x*w);
    mi=min(mi,x*z);
}
int main(){
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    double ll=0,rr=1e9;
    REP(k,100){
        double mm=(ll+rr)*0.5;
        double x1,y1,x2,y2;
        get(a-mm,a+mm,d-mm,d+mm,x1,y1);
        get(b-mm,b+mm,c-mm,c+mm,x2,y2);
        if(y1<x2||y2<x1)ll=mm;
        else rr=mm;
    }
    printf("%.12f\n",(ll+rr)*0.5);
    return 0;
}