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
void ADD(int &x,LL v){
    x=(x+v)%MOD;
}
int dp[2222][4][2222];
char a[2222];
char b[2222];
int main(){
    DRII(m,d);
    RS(a);
    RS(b);
    int n=LEN(a);
    REP(i,n){
        a[i]-='0';
        b[i]-='0';
    }
    dp[0][0][0]=1;
    REP(i,n){
        REP(j,4){
            REP(k,m){
                int bb=a[i],uu=b[i];
                if(j&1)bb=0;
                if(j&2)uu=9;
                REPP(l,bb,uu+1){
                    if(i%2==1){
                        if(l!=d)continue;
                    }
                    else{
                        if(l==d)continue;
                    }

                    int nxt=j;
                    if(l!=bb)nxt|=1;
                    if(l!=uu)nxt|=2;
                    ADD(dp[i+1][nxt][(k*10+l)%m],dp[i][j][k]);
                }
            }
        }
    }
    int an=0;
    REP(i,4)ADD(an,dp[n][i][0]);
    cout<<an;
    return 0;
}