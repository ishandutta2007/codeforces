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
LL mul[2][SIZE],tt[SIZE];
int main(){
    DRI(m);
    LL an=1;
    map<int,int>H;
    REP(i,m){
        DRI(x);
        H[x]++;
    }
    map<int,int>::iterator it=H.begin();
    int id=1;
    while(it!=H.end()){
        tt[id++]=it->S+1;
        it++;
    }
    int n=id;
    mul[0][0]=mul[1][n]=1;
    REPP(i,1,n)mul[0][i]=mul[0][i-1]*tt[i]%(MOD-1);
    for(int i=n-1;i>0;i--)mul[1][i]=mul[1][i+1]*tt[i]%(MOD-1);
    it=H.begin();
    id=1;
    while(it!=H.end()){
        LL me=1,ker=1;
        REP(j,it->S){
            ker=ker*it->F%MOD;
            me=me*ker%MOD;
        }
        an=an*mypow(me,mul[0][id-1]*mul[1][id+1])%MOD;
        id++;
        it++;
    }
    cout<<an;
    return 0;
}