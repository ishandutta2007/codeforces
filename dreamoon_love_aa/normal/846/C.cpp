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
const int SIZE = 5e3+10;
LL a[SIZE],sum[SIZE];
PLL ma[SIZE];
LL get(int x,int y){
    if(!x)return sum[y-1];
    return sum[y-1]-sum[x-1];
}
int main(){
    DRI(n);
    ma[0]=MP(0,0);
    REP(i,n){
        DRI(x);
        if(i){
            sum[i]+=sum[i-1];
            ma[i]=ma[i-1];
        }
        sum[i]+=x;
        ma[i]=max(ma[i],MP(sum[i],i+1LL));
    }
    LL res=0;
    int an[3]={};
    REPP(j,1,n+1)REPP(i,1,j+1){
        if(get(i,j)+ma[i-1].F>res){
            res=get(i,j)+ma[i-1].F;
            an[0]=ma[i-1].S;
            an[1]=i;
            an[2]=j;
        }
    }
    REP(i,3)printf("%d%c",an[i]," \n"[i==2]);
    return 0;
}