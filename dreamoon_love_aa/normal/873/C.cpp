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
int a[111][111];
PII solve(int d[],int n,int k){
    PII ret=MP(0,0);
    int sub=0,ma=0;
    REP(i,n){
        if(d[i]==0)continue;
        int me=0;
        for(int j=i;j<i+k&&j<n;j++){
            me+=d[j];
        }
        if(me>ma){
            ma=me;
            ret.S=sub;
        }
        sub+=d[i];
    }
    ret.F=ma;
    return ret;
}
int main(){
    DRIII(n,m,k);
    REP(i,n)REP(j,m)RI(a[j][i]);
    PII an=MP(0,0);
    REP(i,m){
        PII res=solve(a[i],n,k);
        an.F+=res.F;
        an.S+=res.S;
    }
    return 0*printf("%d %d\n",an.F,an.S);
}