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
int a[10][10];
int n,K;
double an;
void dfs(int lv){
    if(lv==K){
        REP(i,n)REPP(j,i+1,n){
            if(a[lv][i]>a[lv][j])an++;
        }
        return;
    }
    REP(i,n)REPP(j,i,n){
        REP(k,n)a[lv+1][k]=a[lv][k];
        reverse(a[lv+1]+i,a[lv+1]+j+1);
        dfs(lv+1);
    }
}
int main(){
    RII(n,K);
    REP(i,n)RI(a[0][i]);
    dfs(0);
    REP(i,K)an/=n*(n+1)/2;
    printf("%.12f\n",an);
    return 0;
}