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
int my_gcd(int x,int y){
    if(!x||!y)return abs(x)+abs(y);
    return __gcd(abs(x),abs(y));
}
int main(){
    DRI(n);
    VI d;
    int gg=0;
    REP(i,n){
        DRI(x);
        d.PB(x);
        gg=__gcd(gg,x);
    }
    if(gg!=1)puts("YES\n0");
    else{
        int an=0,v=0;
        REP(i,n){
            if(d[i]%2)v++;
            else{
                if(v%2==0)an+=v/2;
                else an+=v/2+2;
                v=0;
            }
        }
        if(v%2==0)an+=v/2;
        else an+=v/2+2;
        printf("YES\n%d\n",an);
    }
    return 0;
}