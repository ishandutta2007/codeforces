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
const int SIZE = 2e5+10;
double dp[51][SIZE];
int a[SIZE];
double r[SIZE],sum_r[SIZE];
LL sum[SIZE];
void build(int n){
    REPP(i,1,n+1){
        sum[i]=a[i]+sum[i-1];
        sum_r[i]=1./a[i]+sum_r[i-1];
        r[i]=r[i-1]+1.*sum[i]/a[i];
    }
}
double get(int x,int y){
    return r[y]-r[x-1]-sum[x-1]*(sum_r[y]-sum_r[x-1]);
}
void cal(int lv,int L,int R,int ll,int rr){
    int mm=(L+R)>>1;
    int id=0;
    double mi=1e100;
    REPP(i,ll,min(mm,rr)){
        double v=dp[lv-1][i]+get(i+1,mm);
        if(v<mi){
            mi=v;
            id=i;
        }
    }
    dp[lv][mm]=mi;
    if(mm>L)cal(lv,L,mm-1,ll,min(mm-1,id+1));
    if(mm<R)cal(lv,mm+1,R,id,rr);
}
int main(){
    DRII(n,k);
    REP(i,n)RI(a[i+1]);
    build(n);
    REPP(i,1,n+1)dp[1][i]=get(1,i);
    REPP(i,2,k+1){
        cal(i,i,n,i-1,n+1);
    }
    printf("%.12f\n",dp[k][n]);
    return 0;
}