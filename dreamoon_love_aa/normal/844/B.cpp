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
int a[55][55];
LL two[55];
int main(){
    two[0]=1;
    REPP(i,1,55)two[i]=two[i-1]*2;
    DRII(N,M);
    REP(i,N)REP(j,M)RI(a[i][j]);
    LL an=0;
    REP(i,N){
        int cnt[2]={};
        REP(j,M){
            cnt[a[i][j]]++;
        }
        REP(j,2){
            an+=two[cnt[j]];
            an-=1+cnt[j];
        }
    }
    REP(i,M){
        int cnt[2]={};
        REP(j,N){
            cnt[a[j][i]]++;
        }
        REP(j,2){
            an+=two[cnt[j]];
            an-=1+cnt[j];
        }
    }
    an+=N*M;
    printf("%I64d\n",an);
    return 0;
}