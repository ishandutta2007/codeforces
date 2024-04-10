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
int an[333][333];
int main(){
    DRI(n);
    int odd=1;
    REP(i,n){
        an[i][n/2]=odd;
        odd+=2;
    }
    REP(i,n){
        if(!an[n/2][i]){
            an[n/2][i]=odd;
            odd+=2;
        }
    }
    for(int i=0;i<n/2;i++)
        for(int j=0;j<n/2;j++){
            if(odd<=n*n){
                an[i][j]=odd;odd+=2;
                an[n-1-i][n-1-j]=odd;odd+=2;
                an[n-1-i][j]=odd;odd+=2;
                an[i][n-1-j]=odd;odd+=2;
            }
        }
    int even=2;
    REP(i,n)REP(j,n){
        if(!an[i][j]){
            an[i][j]=even;
            even+=2;
        }
    }
    REP(i,n){
        REP(j,n)printf("%d ",an[i][j]);
        puts("");
    }
    return 0;
}