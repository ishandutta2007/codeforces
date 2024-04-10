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
int an[SIZE],a[SIZE],ma[SIZE],mi[SIZE];
int rmq_ma[20][SIZE],rmq_mi[20][SIZE];
int qq_mi(int L,int R){
    int i=0;
    while((1<<(i+1))<=R-L+1)i++;
    return max(rmq_mi[i][L],rmq_mi[i][R-(1<<i)+1]);
}
int qq_ma(int L,int R){
    int i=0;
    while((1<<(i+1))<=R-L+1)i++;
    return max(rmq_ma[i][L],rmq_ma[i][R-(1<<i)+1]);
}
int main(){
    DRI(n);
    REP(i,n)RI(a[i]);
    {
        REP(i,n)an[n-1]=max(an[n-1],a[i]);
        an[n-2]=an[n-1];
    }
    REPP(i,1,n-1){
        rmq_ma[0][i]=max(a[i],min(a[i-1],a[i+1]));
        rmq_mi[0][i]=min(a[i],max(a[i-1],a[i+1]));
    }
    REPP(i,1,20){
        for(int j=0;j+(1<<i)<=n;j++){
            rmq_ma[i][j]=max(rmq_ma[i-1][j],rmq_ma[i-1][j+(1<<(i-1))]);
        }
        for(int j=0;j+(1<<i)<=n;j++){
            rmq_mi[i][j]=max(rmq_mi[i-1][j],rmq_mi[i-1][j+(1<<(i-1))]);
        }
    }
    REP(i,n-2){
        int r=n-i;
        if(r%2==1){
            an[i]=qq_mi(r/2,n-1-r/2);
        }
        else{
            an[i]=qq_ma((r-1)/2,n-1-(r-1)/2);
        }
    }
    REP(i,n)printf("%d ",an[i]);
    return 0;
}