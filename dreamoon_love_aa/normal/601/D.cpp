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
const int SIZE = 3e5+10;
int v[SIZE];
int nxt[SIZE][26],sz[SIZE];
char s[SIZE];
VI e[SIZE];
void merge(int x,int y,int &num){
    REP(i,26){
        if(nxt[y][i]){
            if(!nxt[x][i]){
                num+=sz[nxt[y][i]];
                nxt[x][i]=nxt[y][i];
            }
            else{
                sz[x]-=sz[nxt[x][i]];
                merge(nxt[x][i],nxt[y][i],sz[nxt[x][i]]);
                sz[x]+=sz[nxt[x][i]];
            }
        }
    }
}
void dfs(int x,int lt){
    sz[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
        int c=s[y];
        if(!nxt[x][c]){
            sz[x]+=sz[y];
            nxt[x][c]=y;
        }
        else{
            sz[x]-=sz[nxt[x][c]];
            if(sz[nxt[x][c]]<sz[y]){
                swap(y,nxt[x][c]);
            }

            merge(nxt[x][c],y,sz[nxt[x][c]]);
            sz[x]+=sz[nxt[x][c]];
        }
    }
    v[x]+=sz[x];
}
int main(){
    DRI(N);
    REP(i,N)RI(v[i]);
    RS(s);
    REP(i,N)s[i]-='a';
    REPP(i,1,N){
        DRII(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(0,0);
    PII an=MP(0,0);
    REP(i,N){
        if(an.F<v[i]){
            an=MP(v[i],1);
        }
        else if(an.F==v[i])an=MP(v[i],an.S+1);
    }
    printf("%d\n%d\n",an.F,an.S);
    return 0;
}