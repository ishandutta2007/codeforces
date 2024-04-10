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
char s[111][111][111];
int dx[3]={1,0,0};
int dy[3]={0,1,0};
int dz[3]={0,0,1};
int main(){
    DRIII(N,M,K);
    REPP(i,1,N+1)REPP(j,1,M+1)RS(s[i][j]+1);
    int an=0;
    REPP(i,1,N+1)REPP(j,1,M+1)REPP(k,1,K+1){
        if(s[i][j][k]=='0')continue;
        if(s[i][j][k-1]=='1'&&s[i][j][k+1]=='1'){an++;continue;}
        if(s[i][j-1][k]=='1'&&s[i][j+1][k]=='1'){an++;continue;}
        if(s[i-1][j][k]=='1'&&s[i+1][j][k]=='1'){an++;continue;}
        bool suc=0;
        REP(p,3)REP(q,3){
            if(p==q)continue;
            if(s[i+dx[p]][j+dy[p]][k+dz[p]]=='1'
             &&s[i-dx[q]][j-dy[q]][k-dz[q]]=='1'
             &&s[i+dx[p]-dx[q]][j+dy[p]-dy[q]][k+dz[p]-dz[q]]=='0')suc=1;
        }
        if(suc)an++;
    }
    printf("%d\n",an);
    return 0;
}