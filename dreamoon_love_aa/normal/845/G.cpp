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
int lv[SIZE];
VI e[SIZE],ev[SIZE];
bool u[SIZE];
int v[SIZE];
VI d;
void dfs(int x){
    u[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(u[y]){
            if(lv[y]<lv[x]){
                d.PB(v[x]^v[y]^ev[x][i]);
            }
        }
        else{
            v[y]=v[x]^ev[x][i];
            lv[y]=lv[x]+1;
            dfs(y);
        }
    }
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRIII(x,y,v);x--;y--;
        if(x==y){
            d.PB(v);
            continue;
        }
        e[x].PB(y);
        ev[x].PB(v);
        e[y].PB(x);
        ev[y].PB(v);
    }
    dfs(0);
    int now=v[n-1];
    int it=0;
    for(int i=29;i>=0;i--){
        if(it==SZ(d))break;
        int it2;
        for(it2=it;it2<SZ(d);it2++){
            if((d[it2]>>i)&1){
                if(it2!=it)swap(d[it],d[it2]);
                break;
            }
        }
        if((d[it]>>i)&1){
            REPP(j,it+1,SZ(d)){
                if((d[j]>>i)&1)d[j]^=d[it];
            }
            it++;
        }
    }
    REP(i,SZ(d)){
        if((now^d[i])<now)now^=d[i];
    }
    return 0*printf("%d\n",now);
}