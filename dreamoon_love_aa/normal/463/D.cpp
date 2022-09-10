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
bool big(const vector<int>&X,const vector<int>&Y){
    REP(i,SZ(X)){
        if(X[i]<=Y[i])return 0;
    }
    return 1;
}
int to[SIZE];
vector<int>d[SIZE];
int dp[SIZE];
int main(){
    DRII(n,k);
    REP(i,n){
        DRI(x);
        to[x]=i;
    }
    REPP(i,1,k){
        REP(j,n){
            DRI(x);
            d[to[x]].PB(j);
        }
    }
    int an=0;
    REP(i,n){
        dp[i]=1;
        REP(j,i){
            if(big(d[i],d[j]))dp[i]=max(dp[i],dp[j]+1);
        }
        an=max(an,dp[i]);
    }
    cout<<an;
    return 0;
}