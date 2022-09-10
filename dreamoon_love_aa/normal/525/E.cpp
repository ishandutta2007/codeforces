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
const int SIZE = 1e6+10;
LL fac[20];
LL get(int x){
    if(x>18)return (LL)1e16+1;
    return fac[x];
}
LL S;
void dfs(int x,map<pair<LL,int>,LL>&g,vector<int>&d,LL v,int num){
    if(v>S)return;
    if(x==SZ(d)){
        g[MP(v,num)]++;
        return;
    }
    dfs(x+1,g,d,v,num);
    dfs(x+1,g,d,v+d[x],num);
    dfs(x+1,g,d,v+get(d[x]),num+1);
}
void f(map<pair<LL,int>,LL>&g,vector<int>&d){
    dfs(0,g,d,0,0);
}
int main(){
    int n,k;
    scanf("%d%d%I64d",&n,&k,&S);
    fac[0]=1;
    REPP(i,1,20)fac[i]=fac[i-1]*i;
    vector<int>d[2];
    map<pair<LL,int>,LL>g[2];
    REP(i,n){
        DRI(x);
        d[i&1].PB(x);
    }
    REP(i,2)f(g[i],d[i]);
    LL an=0;
    for(map<pair<LL,int>,LL>::iterator it=g[1].begin();it!=g[1].end();it++){
        for(int j=0;j+it->F.S<=k;j++)an+=g[0][MP(S-it->F.F,j)]*it->S;
    }
    printf("%I64d\n",an);
    return 0;
}