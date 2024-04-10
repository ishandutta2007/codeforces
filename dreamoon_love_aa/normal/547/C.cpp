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
const int SIZE = 500001;
// template end here
vector<int> fac[SIZE];
vector<int> p_fac[SIZE];
int num[SIZE],a[SIZE];
bool v[SIZE];
LL an;
void build(){
    REPP(i,1,SIZE){
        bool pp=0;
        if(SZ(fac[i])==1)pp=1;
        for(int j=i;j<SIZE;j+=i)fac[j].PB(i);
        if(pp&&i!=1){
            for(int j=i;j<SIZE;j+=i)p_fac[j].PB(i);
        }
    }
}
int me;
void dfs(int x,int v,int ty){
    if(x==SZ(p_fac[me])){
        an+=ty*num[v];
        return;
    }
    dfs(x+1,v*p_fac[me][x],-ty);
    dfs(x+1,v,ty);
}
int main(){
    build();
    DRII(n,q);
    REP(i,n)RI(a[i]);
    REP(i,q){
        DRI(x);
        x--;
        me=a[x];
        if(v[x]){
            REP(i,SZ(fac[me])){
                num[fac[me][i]]--;
            }
            dfs(0,1,-1);
        }
        else{
            dfs(0,1,1);
            REP(i,SZ(fac[me])){
                num[fac[me][i]]++;
            }
        }
        v[x]=!v[x];
        printf("%I64d\n",an);
    }
    return 0;
}