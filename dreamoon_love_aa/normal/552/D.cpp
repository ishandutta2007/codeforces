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
int x[SIZE],y[SIZE];
int my_gcd(int x,int y){
    x=abs(x);
    y=abs(y);
    if(!x||!y)return x+y;
    return __gcd(x,y);
}
int main(){
    DRI(n);
    REP(i,n){
        RII(x[i],y[i]);
    }
    int an=n*(n-1)/2LL*(n-2)/3;
    map<pair<PII,int>,int>H;
    REP(i,n)REP(j,i){
        int dx=x[i]-x[j];
        int dy=y[i]-y[j];
        int gg=my_gcd(dx,dy);
        dx/=gg;dy/=gg;
        if(MP(dx,dy)<MP(0,0)){
            dx=-dx;
            dy=-dy;
        }
        H[MP(MP(dx,dy),dy*x[i]-dx*y[i])]++;
    }
    map<int,int>to;
    REPP(i,2,n+1){
        to[i*(i-1)/2]=i*(i-1)/2LL*(i-2)/3;
    }
    for(map<pair<PII,int>,int>::iterator it=H.begin();it!=H.end();it++){
        int v=it->S;
        an-=to[v];
    }
    cout<<an;
    return 0;
}