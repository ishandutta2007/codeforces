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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
int n;
int x[SIZE],y[SIZE],v[SIZE],h[SIZE],num[SIZE];
vector<pair<int,int> >e[SIZE];
LL sum[SIZE];
LL all=0;
void dfs1(int x,int lt,int v){
    h[x]=v;
    num[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs1(y,x,v+1);
        num[x]+=num[y];
        all+=(LL)num[y]*(n-num[y])*e[x][i].S;
    }
}
int main(){
    RI(n);
    REPP(i,1,n){
        RIII(x[i],y[i],v[i]);
        e[x[i]].PB(MP(y[i],v[i]));
        e[y[i]].PB(MP(x[i],v[i]));
    }
    dfs1(1,1,0);
    DRI(Q);
    while(Q--){
        DRII(id,u);
        int low;
        if(h[x[id]]<h[y[id]])low=y[id];
        else low=x[id];
        all-=(LL)num[low]*(n-num[low])*(v[id]-u);
        v[id]=u;
        printf("%.9f\n",all*6./(n*(n-1LL)));
    }
    return 0;
}