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
const int SIZE = 1e6+10;
char s[1000][1000];
int R[1000][1000],C[1000][1000];
int main(){
    DRII(n,m);
    REPP(i,1,n+1)RS(s[i]+1);
    REPP(i,1,n+1)REPP(j,1,m+1){
        if(s[i][j]=='.'&&s[i+1][j]=='.')C[i][j]=1;
        if(s[i][j]=='.'&&s[i][j+1]=='.')R[i][j]=1;
    }
    REPP(i,1,n+1)REPP(j,1,m+1){
        C[i][j]+=C[i][j-1];
        R[i][j]+=R[i][j-1];
    }
    REPP(i,1,n+1)REPP(j,1,m+1){
        C[i][j]+=C[i-1][j];
        R[i][j]+=R[i-1][j];
    }
    DRI(Q);
    while(Q--){
        DRII(x1,y1);
        DRII(x2,y2);
        int an=0;
        if(x2>x1)an+=C[x2-1][y2]+C[x1-1][y1-1]-C[x2-1][y1-1]-C[x1-1][y2];
        if(y2>y1)an+=R[x2][y2-1]+R[x1-1][y1-1]-R[x2][y1-1]-R[x1-1][y2-1];
        printf("%d\n",an);
    }
    return 0;
}