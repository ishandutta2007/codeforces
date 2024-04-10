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
const int SIZE = 30001;
int dp[SIZE][500];
int gem[SIZE];
void fresh(int &x,int v){
    if(x<v)x=v;
}
int main(){
    MS1(dp);
    DRII(n,d);
    int st=max(1,d-250);
    int ma=0;
    REP(i,n){
        DRI(x);
        gem[x]++;
        ma=max(ma,x);
    }
    dp[d][d-st]=gem[d];
    int an=gem[d];
    REPP(i,1,ma){
        REP(k,500){
            if(dp[i][k]==-1)continue;
            int me=k+st;
            REPP(j,-1,2){
                if(me+j<st)continue;
                int you=i+me+j;
                if(you>ma)continue;
                fresh(dp[you][me+j-st],dp[i][k]+gem[you]);
                fresh(an,dp[i][k]+gem[you]);
            }
        }
    }
    printf("%d\n",an);
    return 0;
}