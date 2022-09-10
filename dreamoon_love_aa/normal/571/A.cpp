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
LL dp[SIZE];
LL f(int s,int m,int l){
    LL res=0;
    REP(i,l+1){
        int ker=min(l-i,m+i-s);
        if(ker>=0)res+=dp[ker];
    }
    return res;
}
int main(){
    dp[0]=1;
    REPP(i,1,SIZE){
        dp[i]=dp[i-1]+i+1;
    }
    DRIII(a,b,c);
    DRI(l);
    LL an=(l+3LL)*(l+1)*(l+2)/6;
    an-=f(a+b,c,l);
    an-=f(a+c,b,l);
    an-=f(c+b,a,l);
    cout<<an<<endl;
    return 0;
}