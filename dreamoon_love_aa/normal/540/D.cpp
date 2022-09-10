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
double dp[101][101][101][3];
bool used[101][101][101];
void f(int r,int s,int p){
    if(used[r][s][p])return;
    used[r][s][p]=1;
    int all=(r+s+p);
    if(all==r)dp[r][s][p][0]=1;
    if(all==s)dp[r][s][p][1]=1;
    if(all==p)dp[r][s][p][2]=1;
    int qq=r*s+s*p+p*r;
    if(r&&s){
        f(r,s-1,p);
        REP(i,3)dp[r][s][p][i]+=dp[r][s-1][p][i]*(r*s)/(qq);
    }
    if(s&&p){
        f(r,s,p-1);
        REP(i,3)dp[r][s][p][i]+=dp[r][s][p-1][i]*(s*p)/(qq);
    }
    if(p&&r){
        f(r-1,s,p);
        REP(i,3)dp[r][s][p][i]+=dp[r-1][s][p][i]*(r*p)/(qq);
    }
}
int main(){
    DRIII(r,s,p);
    f(r,s,p);
    REP(i,3){
        if(i)printf(" ");
        printf("%.12f",dp[r][s][p][i]);
    }
    puts("");
    return 0;
}