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
char A[SIZE];
LL d[SIZE];
int len;
vector<LL>D;
LL dp[2][4000][2][2];
void ADD(LL &x,LL v){
    x=(x+v)%MOD;
}
LL CC(LL x){
    return x*(x-1)/2%MOD;
}
LL con(LL x,LL y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2%MOD;
}
int main(){
    DRII(p,a);
    RS(A);
    len=LEN(A);
    REP(i,len){
        d[len-1-i]=A[i]-'0';
    }
    int top=len-1;
    while(top>=0){
        LL r=0;
        for(int i=top;i>=0;i--){
            r*=10;
            d[i]+=r;
            r=d[i]%p;
            d[i]/=p;
        }
        D.PB(r);
        while(top>=0&&d[top]==0)top--;
    }
    if(a>=SZ(D))return 0*puts("0");
    int now=0,nxt=1;
    dp[now][0][1][0]=1;
    for(int i=SZ(D)-1;i>=0;i--){
        MS0(dp[nxt]);
        REP(j,a+1){
            ADD(dp[nxt][j][1][0],dp[now][j][1][1]*(p-1-D[i]));
            ADD(dp[nxt][min(j+1,a)][1][1],dp[now][j][1][1]*(p-D[i]));
            ADD(dp[nxt][j][0][0],dp[now][j][1][1]*con(p-D[i],p-1));
            ADD(dp[nxt][min(j+1,a)][0][1],dp[now][j][1][1]*con(p-D[i]+1,p));

            ADD(dp[nxt][j][1][0],dp[now][j][1][0]*(D[i]+1));
            ADD(dp[nxt][min(j+1,a)][1][1],dp[now][j][1][0]*D[i]);
            ADD(dp[nxt][j][0][0],dp[now][j][1][0]*con(1,D[i]));
            ADD(dp[nxt][min(j+1,a)][0][1],dp[now][j][1][0]*con(1,D[i]-1));

            ADD(dp[nxt][j][0][0],dp[now][j][0][1]*con(1,p-1));
            ADD(dp[nxt][min(j+1,a)][0][1],dp[now][j][0][1]*con(1,p));
                
            ADD(dp[nxt][j][0][0],dp[now][j][0][0]*con(1,p));
            ADD(dp[nxt][min(j+1,a)][0][1],dp[now][j][0][0]*con(1,p-1));
        }
        swap(now,nxt);
    }
    LL an=0;
    REP(j,2)
        ADD(an,dp[now][a][j][0]);
    cout<<an;
    return 0;
}