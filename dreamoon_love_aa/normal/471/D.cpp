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
const int SIZE = 5e5;
int a[SIZE],b[SIZE],d[SIZE],far[SIZE];
int main(){
    DRII(n,w);
    REP(i,n)RI(a[i]);
    REP(i,w)RI(b[i]);
    if(w==1)printf("%d\n",n);
    else{
        if(n<w){
            puts("0");
            return 0;
        }
        REPP(i,1,n)a[i-1]=a[i]-a[i-1];
        REPP(i,1,w)b[i-1]=b[i]-b[i-1];
        n--;
        w--;
        int ll=0,rr=0,an=0;
        REP(i,n)b[i+w]=a[i];
        REPP(i,1,n+w){
            int st=0;
            if(rr>i)st=min(rr-i,far[i-ll]);
            for(;i+st<n+w&&b[st+i]==b[st];st++);
            far[i]=st;
            if(i+st>rr){
                ll=i;
                rr=st+i;
            }
            if(far[i]>=w&&i>=w)an++;
        }
        printf("%d\n",an);
    }
    return 0;
}