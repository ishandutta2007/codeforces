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
int fix(int x){
    for(int i=2;i*i<=x;i++){
        while(x%(i*i)==0)x/=i*i;
    }
    return x;
}
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
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
void build(){
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
LL dp[301][301];
int main(){
    build();
    DRI(n);
    map<int,int>H;
    REP(i,n){
        DRI(x);
        H[fix(x)]++;
    }
    VI d;
    for(auto it=H.begin();it!=H.end();it++){
        d.PB(it->S);
    }
    sort(ALL(d));
    int now=d[0]+1;
    dp[d[0]-1][2]=fac[d[0]];
    REPP(i,1,SZ(d)){
        for(int same=now;same>=0;same--){
            int dif=now-same;
            if(!dp[same][dif])continue;
            for(int j=1;j<=d[i]&&j<=now;j++){
                for(int k=0;k<=same&&k<=j;k++){
                    int nxt_same=same-k+d[i]-j;
                    int nxt_dif=now+d[i]-nxt_same;
                    ADD(dp[nxt_same][nxt_dif],dp[same][dif]*C(same,k)%MOD*C(dif,j-k)%MOD*C(d[i]-1,j-1)%MOD*fac[d[i]]);
                }
            }
        }
        now+=d[i];
    }
    cout<<dp[0][now]<<endl;
    return 0;
}