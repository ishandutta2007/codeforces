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

int BIT[2][SIZE];
void ins(int bit[],int x,int v){
    for(;x;x-=x&-x)bit[x]+=v;
}
int qq(int bit[],int x){
    int res=0;
    for(;x<SIZE;x+=x&-x)res+=bit[x];
    return res;
}
VI e[SIZE];
int id,L[SIZE],R[SIZE],a[SIZE],lv[SIZE];
void dfs(int x,int lt,int v){
    L[x]=R[x]=id++;
    lv[x]=v;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x,v+1);
        R[x]=R[y];
    }
}
int main(){
    id=1;
    DRII(n,m);
    REPP(i,1,n+1)RI(a[i]);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,1,0);
    REP(k,m){
        DRI(ty);
        DRI(x);
        if(ty==1){
            DRI(v);
            ins(BIT[lv[x]&1],R[x],v);
            ins(BIT[lv[x]&1],L[x]-1,-v);
        }
        else printf("%d\n",a[x]+qq(BIT[lv[x]&1],L[x])-qq(BIT[(lv[x]&1)^1],L[x]));
    }
    return 0;
}