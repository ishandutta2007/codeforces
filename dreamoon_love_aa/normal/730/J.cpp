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
const int SIZE = 1e4+10;
int a[SIZE],b[SIZE];
PII dp[SIZE];
int main(){
    VI d;
    DRI(n);
    int sum=0;
    REP(i,n){
        RI(a[i]);
        sum+=a[i];
    }
    REP(i,n){
        RI(b[i]);
        d.PB(b[i]);
    }
    sort(ALL(d));
    reverse(ALL(d));
    int need=0,now=0;
    REP(i,SZ(d)){
        need++;
        now+=d[i];
        if(now>=sum)break;
    }
    REP(i,SIZE)dp[i]=MP(-MOD,0);
    dp[0]=MP(0,0);
    REP(i,n){
        for(int j=SIZE-1;j>=0;j--){
            if(dp[j].F==-MOD)continue;
            dp[j+b[i]]=max(dp[j+b[i]],MP(dp[j].F-1,dp[j].S+a[i]));
        }
    }
    int ma=0;
    for(int i=sum;i<SIZE;i++){
        if(dp[i].F==-need)ma=max(ma,dp[i].S);
    }
    printf("%d %d\n",need,sum-ma);
    return 0;
}