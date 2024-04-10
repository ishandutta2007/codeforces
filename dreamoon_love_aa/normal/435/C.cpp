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
using namespace std;
#define SS(X,Y) s[(X)+1100][(Y)]
const int SIZE = 1010;
int a[SIZE],x[SIZE],y[SIZE];
char s[2200][2200];
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i]);
        x[i+1]=x[i]+a[i];
        if(i&1)y[i+1]=y[i]-a[i];
        else y[i+1]=y[i]+a[i];
    }
    REP(i,n){
        if(i&1){
            for(int j=0;x[i]+j<x[i+1];j++)SS(y[i]-j-1,x[i]+j) = '\\';
        }
        else{
            for(int j=0;x[i]+j<x[i+1];j++)SS(y[i]+j,x[i]+j) = '/';
        }
    }
    for(int i=2199;i>=0;i--){
        bool ha=false;
        for(int j=0;j<2200;j++){
            if(s[i][j])ha=true;
        }
        if(!ha)continue;
            REP(k,x[n]){
                if(s[i][k])putchar(s[i][k]);
                else putchar(' ');
            }
            puts("");
    }
    return 0;
}