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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
// template end here
char s[20][25];
int a[20][25];
int dp[1<<20];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
PII d[800];
int dn;
int main(){
    DRII(n,m);
    REP(i,n)RS(s[i]);
    REP(i,n)REP(j,m){
        RI(a[i][j]);
    }
    REP(i,1<<n)dp[i]=INF;
    dp[0]=0;
    REP(i,m){
        vector<pair<char,int> >pp;
        REP(j,n){
            d[dn++]=MP(1<<j,a[j][i]);
            pp.PB(MP(s[j][i],j));
        }
        sort(ALL(pp));
        for(int j=0,k;j<SZ(pp);j=k){
            int sum=0;
            int ma=0;
            int xx=0;
            for(k=j;k<SZ(pp)&&pp[j].F==pp[k].F;k++){
                sum+=a[pp[k].S][i];
                xx|=1<<pp[k].S;
                maa(ma,a[pp[k].S][i]);
            }
            d[dn++]=MP(xx,sum-ma);
        }
    }
    REP(i,1<<n){
        REP(j,dn){
            mii(dp[i|d[j].F],dp[i]+d[j].S);
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
    return 0;
}