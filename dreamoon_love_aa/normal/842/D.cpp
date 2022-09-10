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
const int BB=20;
map<int,int>H[BB];
int solve(int x){
    int ret=0,me=0;
    for(int i=BB-1;i>=0;i--){
        ret|=x&(1<<i);
        if(H[i][ret]==(1<<i)){
            ret^=1<<i;
            me|=1<<i;
        }
    }
    return me;
}
int main(){
    DRII(n,m);
    VI a;
    REP(i,n){
        DRI(x);
        a.PB(x);
    }
    sort(ALL(a));
    a.resize(unique(ALL(a))-a.begin());
    n=SZ(a);
    REP(i,n){
        int mask=0;
        for(int j=BB-1;j>=0;j--){
            mask|=1<<j;
            H[j][a[i]&mask]++;
        }
    }
    int now=0;
    REP(i,m){
        DRI(x);
        now^=x;
        printf("%d\n",solve(now));
    }
    return 0;
}