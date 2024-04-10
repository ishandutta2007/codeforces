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
bitset<2000>A[2000],B[2000],C[2000];
PII p[SIZE];
int main(){
    DRII(n,m);
    REP(i,m){
        RII(p[i].F,p[i].S);
        p[i].F--;p[i].S--;
        A[p[i].F][p[i].S]=1;
    }
    REP(i,n){
        B[i][i]=1;
    }
    REP(i,n){
        int id=-1;
        REPP(j,i,n){
            if(A[j][i]){
                id=j;
                break;
            }
        }
        if(id!=i){
            swap(A[i],A[id]);
            swap(B[i],B[id]);
        }
        REP(j,n){
            if(i==j)continue;
            if(A[j][i]){
                A[j]^=A[i];
                B[j]^=B[i];
            }
        }
    }
    REP(i,m){
        if(!B[p[i].S][p[i].F])puts("YES");
        else puts("NO");
    }
    return 0;
}