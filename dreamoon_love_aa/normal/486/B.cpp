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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e2+10;
int A[SIZE][SIZE];
int B[SIZE][SIZE];
int main(){
    DRII(n,m);
    REP(i,n)REP(j,m)B[i][j]=1;
    REP(i,n)REP(j,m){
        RI(A[i][j]);
        if(!A[i][j]){
            REP(k,SIZE)B[i][k]=B[k][j]=0;
        }
    }
    REP(i,n)REP(j,m){
        int now=0;
        REP(k,m)now|=B[i][k];
        REP(k,n)now|=B[k][j];
        if(now!=A[i][j]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    REP(i,n){
        REP(j,m)printf("%d ",B[i][j]);
        puts("");
    }
    return 0;
}