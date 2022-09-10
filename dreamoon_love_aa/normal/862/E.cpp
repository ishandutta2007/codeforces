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
int b[SIZE];
void answer(VL& d,LL v){
    int it=lower_bound(ALL(d),-v)-d.begin();
    LL an=1e18;
    if(it!=SZ(d))an=min(an,abs(d[it]+v));
    it--;
    if(it>=0)an=min(an,abs(d[it]+v));
    printf("%I64d\n",an);
}
int main(){
    DRIII(n,m,q);
    LL base=0;
    REP(i,n){
        DRI(x);
        if(i&1)base-=x;
        else base+=x;
    }
    LL now=0;
    VL d;
    REPP(i,1,m+1){
        RI(b[i]);
        if(i&1)now-=b[i];
        else now+=b[i];
        if(i>=n){
            if((i-n)%2==0)d.PB(now);
            else d.PB(-now);
            if((i-n+1)&1)now+=b[i-n+1];
            else now-=b[i-n+1];
        }
    }
    sort(ALL(d));
    answer(d,base);
    while(q--){
        DRIII(x,y,v);
        if((y-x+1)%2==1){
            if(x&1)base+=v;
            else base-=v;
        }
        answer(d,base);
    }
    return 0;
}