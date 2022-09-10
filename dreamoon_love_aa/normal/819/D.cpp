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
int a[SIZE],an[SIZE];
// a*x+b*y=z
struct gcd_t {long long x,y,z;};
gcd_t gcd(long long a,long long b) {
    if(b==0)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
int main(){
    DRII(T,n);
    int sum=0;
    REP(i,n){
        RI(a[i]);
        sum+=a[i];
        sum%=T;
    }
    if(!sum){
        set<int>H;
        int now=0;
        REP(i,n){
            if(!H.count(now))an[i]=1;
            H.insert(now);
            now=(now+a[i+1])%T;
        }
    }
    else{
        int gg=__gcd(sum,T);
        map<PII,int>H;
        int now=0;
        REP(i,n){
            int r=now%gg;
            int d=now/gg;
            gcd_t res=gcd(sum/gg,T/gg);
            d=res.x*(LL)d%(T/gg);
            if(d<0)d+=T/gg;
            if(H.count(MP(r,d))==0){
                H[MP(r,d)]=i;
            }
            now=(now+a[i+1])%T;
        }
        auto it=H.begin();
        while(it!=H.end()){
            auto it2=it;
            pair<PII,int> lt=*it2;
            for(it2++;it2!=H.end()&&it2->F.F==it->F.F;it2++){
                an[lt.S]=it2->F.S-lt.F.S;
                lt=*it2;
            }
            if(lt.S==it->S)an[lt.S]=T/gg;
            else an[lt.S]=it->F.S+T/gg-lt.F.S;
            it=it2;
        }
    }
    REP(i,n)printf("%d%c",an[i]," \n"[i==n-1]);
    return 0;
}