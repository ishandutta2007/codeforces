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
int cul[4001],a[4001];
int n,dp[2401][200][100][2];
bool u[2401][200][100][2];
int f(int Ln,int num_dif,int k,int player){
    if(u[Ln][abs(num_dif)][k][player])return dp[Ln][abs(num_dif)][k][player];
    u[Ln][abs(num_dif)][k][player]=1;
    int Rn=Ln+num_dif;
    if(n-Ln-Rn<k)return 0;
    if(!player){
        int v1=-f(Ln+k,num_dif-k,k,1)+cul[Ln+k]-cul[Ln];
        int v2=-INF;
        if(n-Ln-Rn>=k+1){
            v2=-f(Ln+k+1,num_dif-k-1,k+1,1)+cul[Ln+k+1]-cul[Ln];
        }
        return dp[Ln][abs(num_dif)][k][player]=max(v1,v2);
    }
    else{
        int v1=-f(Ln,num_dif+k,k,0)+cul[n-Rn]-cul[n-Rn-k];
        int v2=-INF;
        if(n-Ln-Rn>=k+1){
            v2=-f(Ln,num_dif+k+1,k+1,0)+cul[n-Rn]-cul[n-Rn-k-1];
        }
        return dp[Ln][abs(num_dif)][k][player]=max(v1,v2);
    }
}
int main(){
    RI(n);
    REP(i,n){
        RI(a[i+1]);
        cul[i+1]=a[i+1]+cul[i];
    }
    printf("%d\n",f(0,0,1,0));
    return 0;
}