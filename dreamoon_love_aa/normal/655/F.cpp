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
const int SIZE = 2e6+5;
const int FAC_SIZE = 1e6+1;
void ADD(LL &x,LL v){
    x=(x+v)%MOD;
    if(x<0)x+=MOD;
}
LL fac[SIZE],inv[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
LL mul[FAC_SIZE];
void build(){
    //assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
VI p[FAC_SIZE];
LL cnt[FAC_SIZE];
int main(){
    build();
    REPP(i,2,FAC_SIZE){
        for(int j=i;j<FAC_SIZE;j+=i)p[j].PB(i);
    }
    mul[1]=1;
    REPP(i,2,FAC_SIZE){
        mul[i]=i;
        ADD(mul[i],-mul[1]);
        REP(j,SZ(p[i])-1)
            ADD(mul[i],-mul[p[i][j]]);
        //if(i<=10)printf("mul[%d]=%I64d\n",i,mul[i]);
    }
    DRIII(N,K,Q);
    REP(i,N){
        DRI(x);
        cnt[1]++;
        REP(j,SZ(p[x]))cnt[p[x][j]]++;
    }
    //printf("C(3,3)=%I64d\n",C(3,3));
    LL an=0;
    REPP(i,1,FAC_SIZE){
        //if(cnt[i])printf("cnt[%d]=%I64d,%I64d\n",i,cnt[i],mul[i]);
        ADD(an,C(cnt[i],K)*mul[i]);
    }
    //printf("an=%I64d\n",an);
    REP(i,Q){
        DRI(x);
        ADD(an,-C(cnt[1],K)*mul[1]);
        cnt[1]++;
        ADD(an,C(cnt[1],K)*mul[1]);
        REP(j,SZ(p[x])){
            int y=p[x][j];
            ADD(an,-C(cnt[y],K)*mul[y]);
            cnt[y]++;
            ADD(an,C(cnt[y],K)*mul[y]);
        }
        printf("%I64d\n",an);
    }
    return 0;
}