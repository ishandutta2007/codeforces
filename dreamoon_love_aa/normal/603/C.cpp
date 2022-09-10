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
const int SIZE = 1e7+10;
int dp[SIZE];
void build(){
    REPP(i,1,SIZE){
        bool d[3]={};
        if(!(i&1))d[dp[i/2]]=1;
        d[dp[i-1]]=1;
        for(;dp[i]<2&&d[dp[i]];dp[i]++);
    }
}
int f(int x){
    if(x<SIZE)return dp[x];
    if(x%2==1)return 0;
    bool d[2]={};
    if(!(x&1))d[f(x/2)]=1;
    d[f(x-1)]=1;
    int an=0;
    for(;an<2&&d[an];an++);
    return an;
}
int main(){
    DRII(n,k);
    int res=0;
    if(k%2==0){
        REP(i,n){
            DRI(x);
            if(x==2)res^=2;
            else if(x==1)res^=1;
            else if(x%2==0)res^=1;
        }
    }
    else{
        build();
        REP(i,n){
            DRI(x);
            if(x<SIZE)res^=dp[x];
            else res^=f(x);
        }
    }
    puts(res?"Kevin":"Nicky");
    return 0;
}