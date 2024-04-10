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
int MOD = 1e9+7;
const int SIZE = 1e6+10;
void wrong(){
    puts("-1");
    exit(0);
}
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
int a[SIZE];
int main(){
    DRII(m,n);
    MOD=m;
    LL sum=0;
    REP(i,n){
        RI(a[i]);
        sum+=a[i];
    }
    sort(a,a+n);
    if(n==1){
        printf("%d 0\n",a[0]);
        return 0;
    }
    if(n==m){
        printf("0 1\n");
        return 0;
    }
    LL med=sum%MOD;
    med=med*mypow(n,MOD-2)%MOD;
    if(n%2==1){
        if(!binary_search(a,a+n,med))wrong();
    }
    else{
        if(binary_search(a,a+n,med))wrong();
    }
    REP(i,n){
        if(!binary_search(a,a+n,(int)((med*2-a[i]+m)%m)))wrong();
    }
    int half_n=n/2;
    REP(i,n){
        int another=lower_bound(a,a+n,(int)((med*2-a[i]+m)%m))-a;
        if(another<=i)continue;
        int dif=(a[another]-a[i]+MOD)*mypow(n-1,MOD-2)%MOD;
        int lt_v=(a[i]-dif);
        if(lt_v<0)lt_v+=MOD;
        if(binary_search(a,a+n,lt_v))continue;
        bool suc=1;
        int now=a[i];
        REPP(j,1,half_n){
            now+=dif;
            if(now>=MOD)now-=MOD;
            if(!binary_search(a,a+n,now)){
                suc=0;
                break;
            }
        }
        if(suc){
            printf("%d %d\n",a[i],dif);
            return 0;
        }
    }
    return 0*puts("-1");
}