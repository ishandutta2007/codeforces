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
const int SIZE = 1e5+10;
double dp[SIZE];
int score[SIZE];
int main(){
    DRII(n,m);
    int me=0;
    REP(i,n){
        RI(score[i]);
        me+=score[i];
    }
    if(m==1){
        puts("1");
        return 0;
    }
    int MA=n*m;
    REP(i,MA+1)dp[i]=1;
    REP(i,n){
        for(int j=MA;j>0;j--){
            int U=j-1;
            int D=max(-1,j-m-1);
            if(D>=0)dp[j]=(dp[U]-dp[D]);
            else dp[j]=dp[U];
            if(j-score[i]>=0){
                if(j-score[i]>0)
                    dp[j]-=dp[j-score[i]]-dp[j-score[i]-1];
                else
                    dp[j]-=dp[0];
            }
            dp[j]/=(m-1);
        }
        dp[0]=0;
        REPP(j,1,MA+1)dp[j]+=dp[j-1];
    }
    printf("%.12f\n",dp[me-1]*(m-1)+1);
    return 0;
}