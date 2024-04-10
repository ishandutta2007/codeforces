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
const int SIZE = 3e5+10;
int cnt[SIZE];
LL cc[SIZE];
LL fac[SIZE],inv[SIZE];
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
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
void build(){
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
bitset<SIZE>p;
LL mul[SIZE];
int main(){
    build();
    DRI(n);
    REP(i,n){
        DRI(x);
        cnt[x]++;
    }
    LL an=0;
    mul[n-1]=mypow(2,n-1)-1;
    for(int i=n-2;i>=0;i--){
        mul[i]=mul[i+1]-C(n-1,i)-C(n-1,i+1);
        while(mul[i]<0)mul[i]+=MOD;
    }
    REPP(i,2,SIZE){
        if(!p[i]){
            VI d;
            for(int j=i;j<SIZE;j+=i){
                p[j]=1;
                if(cnt[j]){
                    int me=j/i,c=1;
                    while(me%i==0){
                        c++;
                        me/=i;
                    }
                    REP(k,cnt[j])d.PB(c);
                }
            }
            sort(ALL(d));
            REP(j,SZ(d)){
                ADD(an,d[SZ(d)-1-j]*mul[n-1-j]);
            }
            
        }
    }
    cout<<an;
    return 0;
}