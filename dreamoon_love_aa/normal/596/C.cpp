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
const int MM = 1e5;
const int SIZE = 1e6+10;
VPII w[SIZE];
map<PII,int>dp;
int it[SIZE];
void print_array(VPII&arr){
    REP(i,SZ(arr)){
        printf("%d %d\n",arr[i].F,arr[i].S);
    }
    puts("");
}
int main(){
    DRI(n);
    REP(i,n){
        DRII(x,y);
        w[y-x+MM].PB(MP(x,y));
    }
    REP(i,SIZE)sort(ALL(w[i]));
    VPII res;
    REP(i,n){
        DRI(x);
        if(w[x+MM].size()==it[x+MM])return 0*puts("NO");
        PII me=w[x+MM][it[x+MM]++];
        int ker=dp[MP(me.F,me.S)]=dp[MP(me.F,me.S-1)]+dp[MP(me.F-1,me.S)]-dp[MP(me.F-1,me.S-1)]+1;
        if(ker!=(me.F+1)*(me.S+1))return 0*puts("NO");
        res.PB(me);
    }
    puts("YES");
    print_array(res);
    return 0;
}