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
int a[SIZE],b[SIZE];
int solve(int n){
    PII d[111];
    int dn=0;
    int ret=-1;
    REP(i,n){
        if(dn&&b[i]!=d[dn-1].F&&d[dn-1].S>=3){
            ret+=d[dn-1].S;
            dn--;
        }
        if(!dn||b[i]!=d[dn-1].F){
            d[dn++]=MP(b[i],1);
        }
        else{
            d[dn-1].S++;
        }
    }
    if(dn&&d[dn-1].S>=3){
        ret+=d[dn-1].S;
        dn--;
    }
    return ret;
}
int main(){
    int an=0;
    DRIII(n,k,x);
    REP(i,n)RI(a[i]);
    REP(i,n+1){
        int bn=0;
        REP(j,n){
            if(j<i)b[bn++]=a[j];
            if(j==i)b[bn++]=x;
            if(j>=i)b[bn++]=a[j];
        }
        if(i==n)b[bn++]=x;
        an=max(an,solve(n+1));
    }
    printf("%d\n",an);
    return 0;
}