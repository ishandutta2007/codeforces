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
    double l3,l4,l5;
    cin>>l3>>l4>>l5;
    double r3=l3/cos(PI/6)*0.5;
    double r4=l4*0.5*sqrt(2);
    double r5=l5/cos(PI*54/180)*0.5;
    double h3=sqrt(l3*l3-r3*r3);
    double h4=sqrt(l4*l4-r4*r4);
    double h5=sqrt(l5*l5-r5*r5);
    printf("%.12f\n",l3*1.5*sqrt(r3*r3-l3*l3*0.25)*h3/3
                    +l4*2*sqrt(r4*r4-l4*l4*0.25)*h4/3
                    +l5*2.5*sqrt(r5*r5-l5*l5*0.25)*h5/3);
    return 0;
}