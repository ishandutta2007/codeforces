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
PLL rec[100000];
LL thr(LL x){
    return x*x*x;
}
PLL f(LL x){
    if(x<100000)return rec[x];
    LL ll=1,rr=100000;
    while(ll<rr){
        LL mm=(ll+rr+1)>>1;
        if(thr(mm)<=x)ll=mm;
        else rr=mm-1;
    }
    PLL res1=f(x-thr(ll));
    res1.F++;res1.S+=thr(ll);
    PLL res2=f(thr(ll)-thr(ll-1)-1);
    res2.F++;res2.S+=thr(ll-1);
    return max(res1,res2);
}
void build(){
    vector<LL> d;
    LL now=1;
    while(thr(now)<100000){
        d.PB(thr(now));
        now++;
    }
    rec[0]=MP(0,0);
    REPP(i,1,100000){
        int me=i;
        LL cnt=0;
        for(int j=SZ(d)-1;j>=0;j--){
            while(me>=d[j]){
                me-=d[j];
                cnt++;
            }
        }
        rec[i]=max(rec[i-1],MP((LL)cnt,(LL)i));
    }
}
int main(){
    build();
    LL x;
    cin>>x;
    PLL res=f(x);
    cout<<res.F<<" "<<res.S<<endl;
    return 0;
}