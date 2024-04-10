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
const int SIZE = 5e3+10;
int a[SIZE],dp[2][SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x==-1||x>y)x=y;
}
int main(){
    DRI(n);
    REP(i,n)RI(a[i]);
    int an=n;
    int now=0,nxt=1;
    MS1(dp);
    dp[now][0]=0;
    REP(i,n){
        MS1(dp[nxt]);
        REP(j,n+1){
            if(dp[now][j]!=-1){
                if(a[i]<=j)mii(dp[nxt][min(j,a[i])],dp[now][j]);
                else{
                    mii(dp[nxt][j],dp[now][j]+1);
                    if(a[i]<=n)mii(dp[nxt][a[i]],dp[now][j]+a[i]-j);
                }
            }
        }
        swap(now,nxt);
    }
    REP(i,n+1)
        if(dp[now][i]!=-1)mii(an,dp[now][i]);
    cout<<an;
    return 0;
}