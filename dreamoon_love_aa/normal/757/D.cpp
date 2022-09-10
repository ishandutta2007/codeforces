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
const int SIZE = 1<<20;
char s[99];
int dp[76][SIZE],zero[76];
void ADD(int &x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
int main(){
    DRI(n);
    RS(s+1);
    REPP(i,1,n+1){
        if(s[i]=='0')zero[i]=zero[i-1]+1;
    }
    int an=0;
    REPP(i,1,n+1){
        int me=0;
        for(int j=zero[i];j<i;j++){
            if(s[i-j]=='1'){
                if(j>=5)break;
                me|=1<<j;
            }
            if(me>20)break;
            REP(k,SIZE){
                if(!dp[i-j-1][k])continue;
                ADD(dp[i][k|(1<<(me-1))],dp[i-j-1][k]);
            }
            ADD(dp[i][1<<(me-1)],1);
        }
        for(int j=1;j<SIZE;j=j*2+1){
            ADD(an,dp[i][j]);
        }
    }
    printf("%d\n",an);
    return 0;
}