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
LL fac[SIZE];
void ADD(LL &x,LL v){x=(x+v)%MOD;}
LL mypow(LL x,LL y){
    x%=MOD;
    LL a=1%MOD;
    while(y){
        if(y&1)a=a*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return a;
}
//1-base
struct Difference{
    LL a[SIZE],cc[SIZE];
    int n;
    void build(LL _a[],int _n){
        fac[0]=1;
        REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
        n=_n;
        REPP(i,1,n+1)a[i]=_a[i];
        REPP(i,1,n+1){
            cc[i]=mypow(fac[i-1]*fac[n-i],MOD-2)*a[i]%MOD;
            if((n-i)%2==1)cc[i]=(MOD-cc[i])%MOD;
        }
    }
    LL get(LL x){
        x%=MOD;
        if(x<=n)return a[x];
        LL an=0;
        LL tmp=1;
        REPP(i,1,n+1)tmp=tmp*(x-i)%MOD;
        REPP(i,1,n+1){
            ADD(an,tmp*mypow(x-i,MOD-2)%MOD*cc[i]);
        }
        return an;
    }
}D;
LL a[SIZE];
int main(){
    DRII(n,k);
    REPP(i,1,k+5){
        a[i]=(a[i-1]+mypow(i,k))%MOD;
    }
    D.build(a,k+4);
    cout<<D.get(n);
    return 0;
}