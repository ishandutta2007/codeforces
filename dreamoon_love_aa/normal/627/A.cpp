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
map<pair<LL,LL>,LL>dp;
LL f(LL s,LL x){
    if(dp.count(MP(s,x)))return dp[MP(s,x)];
    if(s<=8){
        int an=0;
        REP(i,s+1){
            if((i^(s-i))==x)an++;
        }
        return dp[MP(s,x)]=an;
    }
    if(x&1){
        if(s&1)
            return dp[MP(s,x)]=2*f(s>>1,x>>1);
        return dp[MP(s,x)]=0;
    }
    else{
        if(s&1)return dp[MP(s,x)]=0;
        return dp[MP(s,x)]=f(s>>1,x>>1)+f((s>>1)-1,x>>1);
    }
}
int main(){
    LL s,x;
    cin>>s>>x;
    printf("%I64d\n",f(s,x)-(s==x)*2);
    return 0;
}