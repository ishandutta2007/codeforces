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
const int MOD = 1e6+3;
const int SIZE = 1e6+10;
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL N,K;
int main(){
    cin>>N>>K;
    if(N<=60&&K>(1LL<<N))puts("1 1");
    else{
        LL sub_two=N;
        LL now=K-1;
        while(now){
            sub_two+=now/2;
            now/=2;
        }
        now=mypow(2,N);
        LL q=1;
        REP(i,K){
            q=q*(now-i)%MOD;
            if(!q)break;
        }
        q=q*mypow(mypow(2,sub_two),MOD-2)%MOD;
        LL p=mypow(mypow(2,N),K)*mypow(mypow(2,sub_two),MOD-2)%MOD;
        q=p-q;
        q%=MOD;
        if(q<0)q+=MOD;
        printf("%lld %lld\n",q,p);
    }
    return 0;
}