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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[64][64];
double dp[64][64][64],dp0[64][64][64];
bool u[64][64][64],u0[64][64][64];
double f0(int L,int R,int id){
    if(u0[L][R][id])return dp0[L][R][id];
    u0[L][R][id]=1;
    if(L+2==R){
        return dp0[L][R][id]=a[id][L*2+1-id]*0.01;
    }
    int mm=(L+R)/2;
    double res=0;
    if(id<mm){
        REPP(i,mm,R){
            res+=f0(L,mm,id)*f0(mm,R,i)*a[id][i]*0.01;
        }
    }
    else{
        REPP(i,L,mm){
            res+=f0(mm,R,id)*f0(L,mm,i)*a[id][i]*0.01;
        }
    }
    return dp0[L][R][id]=res;
}
double f(int L,int R,int id,int lv){
    if(u[L][R][id])return dp[L][R][id];
    u[L][R][id]=1;
    double res=0;
    if(!lv){
        return dp[L][R][id]=a[id][L*2+1-id]*0.01;
    }
    int mm=(L+R)/2;
    if(id<mm){
        REPP(i,mm,R){
            res=max(res,f(L,mm,id,lv-1)+f(mm,R,i,lv-1)+f0(L,R,id)*(1<<lv));
        }
    }
    else{
        REPP(i,L,mm){
            res=max(res,f(mm,R,id,lv-1)+f(L,mm,i,lv-1)+f0(L,R,id)*(1<<lv));
        }
    }
    return dp[L][R][id]=res;
}
int main(){
    DRI(N);
    int all=1<<N;
    REP(i,all)REP(j,all)RI(a[i][j]);
    double an=0;
    REP(i,all)an=max(an,f(0,all,i,N-1));
    printf("%.15f\n",an);
    return 0;
}