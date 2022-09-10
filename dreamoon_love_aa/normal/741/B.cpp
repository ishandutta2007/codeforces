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
const int SIZE = 1111;
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n+1)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
VI gg[SIZE];
int dp[SIZE][SIZE],w[SIZE],b[SIZE];
int main(){
    DRIII(n,m,W);
    REPP(i,1,n+1)RI(w[i]);
    REPP(i,1,n+1)RI(b[i]);
    U.init(n);
    REP(i,m){
        DRII(x,y);
        U.uu(x,y);
    }
    REPP(i,1,n+1){
        gg[U.find(i)].PB(i);
    }
    REPP(i,1,n+1){
        REP(j,W+1)dp[i][j]=dp[i-1][j];
        int sum_W=0,sum_B=0;
        REP(j,SZ(gg[i])){
            int x=gg[i][j];
            sum_W+=w[x];
            sum_B+=b[x];
            for(int k=W-w[x];k>=0;k--){
                maa(dp[i][k+w[x]],dp[i-1][k]+b[x]);
            }
        }
            for(int k=W-sum_W;k>=0;k--){
                maa(dp[i][k+sum_W],dp[i-1][k]+sum_B);
            }
    }
    int an=0;
    REP(i,W+1)an=max(an,dp[n][i]);
    printf("%d\n",an);
    return 0;
}