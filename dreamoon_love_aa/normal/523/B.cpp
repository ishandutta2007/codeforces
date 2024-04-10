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
int a[SIZE];
LL dp[SIZE];
double an[SIZE][3];
int main(){
    int n,T;
    double c;
    cin>>n>>T>>c;
    REP(i,n)RI(a[i+1]);
    double mean=0;
    REPP(i,1,n+1){
        mean=(mean+1.*a[i]/T)/c;
        dp[i]=dp[i-1]+a[i];
        an[i][1]=mean;
        if(i>=T){
            an[i][0]=(dp[i]-dp[i-T])*1./T;
            an[i][2]=fabs(an[i][1]-an[i][0])/an[i][0];
        }
    }
    DRI(m);
    REP(k,m){
        DRI(x);
        printf("%f %f %f\n",an[x][0],an[x][1],an[x][2]);
    }
    return 0;
}