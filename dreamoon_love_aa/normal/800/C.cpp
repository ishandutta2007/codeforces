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
// a*x+b*y=z
struct gcd_t {long long x,y,z;};
gcd_t gcd(long long a,long long b) {
    if(b==0)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
int my_gcd(int x,int y){
    if(!x||!y)return x+y;
    return __gcd(x,y);
}
int ban[SIZE];
VI d[SIZE];
int dp[SIZE],im[SIZE],from[SIZE];
VI res;
void back(int x){
    if(!x)return;
    REP(i,SZ(d[x]))res.PB(d[x][i]);
    if(x==1)return;
    back(from[x]);
}
int main(){
    DRII(n,m);
    REP(i,n){
        DRI(x);
        ban[x]=1;
    }
    REP(i,m){
        if(!ban[i])d[my_gcd(i,m)].PB(i);
    }
    REPP(i,1,m+1){
        if(my_gcd(i,m)==i)im[i]=1;
    }
    MS1(dp);
    dp[1]=SZ(d[1]);
    REPP(i,1,m){
        if(!im[i])continue;
        for(int j=i+i;j<=m;j+=i){
            if(im[j]){
                if(dp[j]<dp[i]+SZ(d[j])){
                    dp[j]=dp[i]+SZ(d[j]);
                    from[j]=i;
                }
            }
        }
    }
    back(m);
    int now=1;
    printf("%d\n",SZ(res));
    for(int i=SZ(res)-1;i>=0;i--){
        gcd_t gg=gcd(now,m);
        int mul=gg.x;
        int z=gg.z;
        mul=(LL)mul*(res[i]/z)%m;
        if(mul<0)mul+=m;
        printf("%d",mul);
        now=res[i];
        if(i)printf(" ");
        else puts("");
    }
    return 0;
}