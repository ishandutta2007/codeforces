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
double p,dp[2002][2002][2][2];
int n,h;
int x[SIZE];
double f(int L,int R,int l_state,int r_state){
    if(L>R)return 0;
    if(dp[L][R][l_state][r_state])
        return dp[L][R][l_state][r_state];
    if(l_state&&x[L-1]+h>x[L]){
        if(L==R&&r_state)return dp[L][R][l_state][r_state]=max(0,min(x[R+1]-x[R]-r_state*h,h));
        return dp[L][R][l_state][r_state]=min(x[L+1]-x[L],h)+f(L+1,R,1,r_state);
    }
    if(r_state&&x[R+1]-h<x[R]){
        if(L==R&&l_state)return dp[L][R][l_state][r_state]=max(0,min(x[L]-x[L-1]-l_state*h,h));
        return dp[L][R][l_state][r_state]=min(x[R]-x[R-1],h)+f(L,R-1,l_state,1);
    }
    if(L==R)return dp[L][R][l_state][r_state]=p*max(0,min(x[L]-x[L-1]-l_state*h,h))
        +(1-p)*max(0,min(x[R+1]-x[R]-r_state*h,h));
    double ret=p*max(0,min(x[L]-x[L-1]-l_state*h,h))
        +(1-p)*max(0,min(x[R+1]-x[R]-r_state*h,h));
    ret+=p*f(L+1,R,0,r_state);
    ret+=(1-p)*f(L,R-1,l_state,0);
    ret+=(1-p)*(min(x[L+1]-x[L],h)+f(L+1,R,1,r_state));
    ret+=p*(min(x[R]-x[R-1],h)+f(L,R-1,l_state,1));
    ret*=0.5;
    return dp[L][R][l_state][r_state]=ret;
}
int main(){
    RII(n,h);
    scanf("%lf",&p);
    REP(i,n)RI(x[i]);
    x[n]=-INF;
    x[n+1]=INF;
    sort(x,x+n+2);
    printf("%.12f\n",f(1,n,0,0));
    return 0;
}