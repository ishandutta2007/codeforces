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
const int SIZE = 1e3+10;
// template end here
PII pp[SIZE];
int dp[2][SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    DRII(n,T);
    REP(i,n){
        DRII(t,q);
        pp[i]=MP(t,q);
    }
    sort(pp,pp+n);
    int lv=0;
    int now=1;
    MS1(dp);
    dp[lv][0]=0;
    pp[n++]=MP(T,0);
    for(int i=0,j;i<n;i=j){
        while(now<pp[i].F){
            MS1(dp[lv^1]);
            REP(k,n+1)maa(dp[lv^1][(k+1)/2],dp[lv][k]);
            lv^=1;
            now++;
        }
        for(j=i;j<n&&pp[j].F==pp[i].F;j++){
            for(int k=n-1;k>=0;k--){
                if(dp[lv][k]>=0)maa(dp[lv][k+1],dp[lv][k]+pp[j].S);
            }
        }
    }
    maa(dp[lv][1],0);
    cout<<dp[lv][1]<<endl;
    return 0;
}