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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],dp[SIZE];
void print(int x){
    if(dp[x])print(dp[x]);
    if(a[dp[x]+1]-a[dp[x]]-2)printf("RUN %d\n",a[dp[x]+1]-a[dp[x]]-2);
    printf("JUMP %d\n",a[x]-a[dp[x]+1]+2);
}
int main(){
    a[0]=-1;
    DRII(n,m);
    DRII(s,d);
    REPP(i,1,n+1)RI(a[i]);
    sort(a+1,a+n+1);
    MS1(dp);
    dp[0]=INF;
    int rr=1;
    REP(i,n){
        if(a[i]+2+s>a[i+1])continue;
        if(dp[i]==-1)continue;
        while(rr<=n&&a[rr]+2-a[i+1]<=d)dp[rr++]=i;
    }
    if(dp[n]==-1)puts("IMPOSSIBLE");
    else{
        print(n);
        if(a[n]+1!=m)printf("RUN %d\n",m-a[n]-1);
    }
    return 0;
}