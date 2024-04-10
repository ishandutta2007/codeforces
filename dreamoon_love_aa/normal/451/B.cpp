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
const int SIZE = 1e5+5;
int a[SIZE],b[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    int sm=SIZE,bi=-1;
    REP(i,n){
        if(b[i]!=a[i]){
            sm=min(sm,i);
            bi=max(bi,i);
        }
    }
    if(bi==-1){
        puts("yes\n1 1\n");
    }
    else{
        reverse(a+sm,a+bi+1);
        bool suc=true;
        REP(i,n){
            if(a[i]!=b[i]){
                suc=false;
            }
        }
        if(!suc)puts("no");
        else{
            puts("yes");
            printf("%d %d\n",sm+1,bi+1);
        }
    }
    return 0;
}