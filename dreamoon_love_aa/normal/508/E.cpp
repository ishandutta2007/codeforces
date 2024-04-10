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
int dp[600][600];
int L[600],R[600];
void print(int ll,int rr){
    if(ll>rr)return;
    int k=dp[ll][rr];
    putchar('(');
    print(ll+1,ll+k/2);
    putchar(')');
    print(ll+k/2+1,rr);
}
int main(){
    DRI(n);
    REP(i,n)RII(L[i],R[i]);
    REP(i,n){
        for(int ll=0;ll+i<n;ll++){
            int rr=ll+i;
            for(int k=1;ll+k/2<=rr;k+=2){
                if(k<L[ll]||k>R[ll])continue;
                if(ll+k/2<rr){
                    if((k==1||dp[ll+1][ll+k/2])&&dp[ll+k/2+1][rr]){
                        dp[ll][rr]=k;
                        break;
                    }
                }
                else{
                    if(ll==rr||dp[ll+1][rr]){
                        dp[ll][rr]=k;
                    }
                }
            }
        }
    }
    if(!dp[0][n-1])puts("IMPOSSIBLE");
    else{
        print(0,n-1);
        puts("");
    }
    return 0;
}