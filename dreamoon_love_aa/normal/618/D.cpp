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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
VI e[SIZE];
int N,X,Y;
int dp[SIZE][3];

template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void dfs(int x,int lt){
    dp[x][0]=1;
    dp[x][1]=dp[x][2]=INF;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
        int tmp[3]={INF,INF,INF};
        tmp[0]=dp[x][0]+min(dp[y][0],min(dp[y][1],dp[y][2]));
        mii(tmp[1],dp[x][1]+min(dp[y][0],min(dp[y][1],dp[y][2])));
        mii(tmp[1],dp[x][0]+min(dp[y][1],dp[y][0])-1);
        mii(tmp[2],dp[x][2]+min(dp[y][0],min(dp[y][1],dp[y][2])));
        mii(tmp[2],dp[x][1]+min(dp[y][1],dp[y][0])-1);
        REP(j,3)dp[x][j]=tmp[j];
        
    }
}
int main(){
    RIII(N,X,Y);
    REPP(i,1,N){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    if(X==Y){
        cout<<X*(N-1LL)<<endl;
        return 0;
    }
    else if(N==2)printf("%d\n",X);
    else{
        if(X<Y){
            dfs(1,1);
            LL cnt=min(dp[1][0],min(dp[1][1],dp[1][2]))-1;
            //printf("cnt:%I64d\n",cnt);
            printf("%I64d\n",cnt*Y+(N-1-cnt)*X);
        }
        else{
            int ma=0;
            REPP(i,1,N+1){
                ma=max(ma,SZ(e[i]));
            }
            if(ma==N-1)printf("%I64d\n",Y*(N-2LL)+X);
            else printf("%I64d\n",Y*(N-1LL));
        }
    }
    return 0;
}