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
int MOD = 1e9+7;
const int SIZE = 1e6+10;
int cnt[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
int main(){
    DRII(n,m);
    DRII(dx,dy);
    if(n==1){
        puts("0 0");
        return 0;
    }
    int p=0;
    REPP(i,1,n){
        if(__gcd(i,n)==1)p++;
    }
    MOD=n;
    int inv=mypow(dx,p-1);
    REP(i,m){
        DRII(x,y);
        int step=(LL)inv*(n-x)%n;
        cnt[(y+(LL)dy*step)%n]++;
    }
    int ma=-1,id;
    REP(i,SIZE){
        if(cnt[i]>ma){
            ma=cnt[i];
            id=i;
        }
    }
    printf("%d %d\n",0,id);
    return 0;
}