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
int an[101][101],p[10000];
int main(){
    DRII(n,m);
    if(n*m==2||n*m==3||(n==2&&m==2))puts("-1");
    else if(n*m==4)printf("3 1 4 2\n");
    else{
        REP(i,n*m)p[i]=i+1;
        while(1){
            random_shuffle(p,p+n*m);
            bool err=0;
            REP(i,n)REP(j,m){
                an[i][j]=p[i*m+j];
                if(i&&abs(an[i][j]-an[i-1][j])==1){
                    err=1;
                    break;
                }
                if(j&&abs(an[i][j]-an[i][j-1])==1){
                    err=1;
                    break;
                }
            }
            if(!err)break;
        }
        REP(i,n)REP(j,m){
            printf("%d%c",an[i][j],j==m-1?'\n':' ');
        }
    }
    return 0;
}