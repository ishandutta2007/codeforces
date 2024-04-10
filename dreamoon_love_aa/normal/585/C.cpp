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
const LL INF = 2e18;
const int SIZE = 1e6+10;
vector<LL> res;
void f(LL x,LL y){
    if(x+y==2)return;
    if(y==1){
        res.PB(x-1);
        return;
    }
    if(x==1){
        res.PB(y-1);
        return;
    }
    if(x>y){
        res.PB(x/y);
        f(x%y,y);
    }
    else{
        res.PB(y/x);
        f(x,y%x);
    }
}
LL MUL(LL x,LL y){
    if(x>INF/y)return INF;
    return x*y;
}
int main(){
    LL x,y;
    cin>>x>>y;
    if(__gcd(x,y)!=1)return 0*puts("Impossible");
    f(x,y);
    REP(k,2){
        PLL X=MP(1,0),Y=MP(0,1);
        bool suc=1;
        REP(i,SZ(res)){
            if(i%2==k){
                Y.F+=MUL(X.F,res[i]);
                Y.S+=MUL(X.S,res[i]);
            }
            else{
                X.F+=MUL(Y.F,res[i]);
                X.S+=MUL(Y.S,res[i]);
            }
            if(X.F+Y.F>x||X.S+Y.S>y)
                break;
        }
        if(X.F+Y.F==x&&X.S+Y.S==y){
            REP(i,SZ(res)){
                printf("%I64d%c",res[i],(i%2==k)?'A':'B');
            }
            puts("");
            return 0;
        }
    }
    puts("Impossible");
    return 0;
}