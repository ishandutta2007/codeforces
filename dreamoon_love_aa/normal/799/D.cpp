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
const LL INF = 1e18;
const int SIZE = 1e6+10;
LL d[SIZE];
int an=-1;
void dfs(int it,LL lt,LL h,LL w,LL a,LL b,int v){
    if(an!=-1&&an<=v)return;
    if(h<=a&&w<=b){
        if(an==-1||an>v)an=v;
        return;
    }
    if(!d[it])return;
    if(h<=a){
        dfs(it+1,lt,h,w,a,b*d[it],v+1);
        return;
    }
    if(w<=b){
        dfs(it+1,lt,h,w,a*d[it],b,v+1);
        return;
    }
    if(d[it]<lt){
        dfs(it+1,lt,h,w,a*d[it],b,v+1);
    }
    dfs(it+1,d[it],h,w,a,b*d[it],v+1);
}
int main(){
    DRII(h,w);
    DRII(a,b);
    DRI(n);
    REP(i,n){
        DRI(x);
        d[i]=x;
    }
    sort(d,d+n,greater<LL>());
    dfs(0,INF,h,w,b,a,0);
    dfs(0,INF,h,w,a,b,0);
    printf("%d\n",an);
    return 0;
}