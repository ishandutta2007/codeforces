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
int a[SIZE];
int in[SIZE][3],b[SIZE];
int main(){
    DRIII(n,q,m);
    REPP(i,1,n+1){
        RI(a[i]);
    }
    REP(i,q)REP(j,3)RI(in[i][j]);
    REP(j,m){
        RI(b[j]);
    }
    for(int i=q-1;i>=0;i--){
        REP(j,m)
            if(b[j]>=in[i][1]&&b[j]<=in[i][2]){
                if(in[i][0]==1){
                    if(b[j]>in[i][1])b[j]--;
                    else b[j]=in[i][2];
                }
                else{
                    b[j]=in[i][1]+in[i][2]-b[j];
                }
            }
    }
    REP(i,m)printf("%d ",a[b[i]]);
    return 0;
}