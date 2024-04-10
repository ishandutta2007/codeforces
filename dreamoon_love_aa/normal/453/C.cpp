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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1e5+1;
vector<int>e[SIZE];
int p[SIZE],used[SIZE],st;
vector<int>an;
void dfs(int x){
    used[x]=1;
    an.PB(x);
    p[x]^=1;
    bool suc=false;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(!used[y]){
            suc=true;
            dfs(y);
            if(p[y]){
                an.PB(x);
                an.PB(y);
                p[y]^=1;
                p[x]^=1;
            }
            an.PB(x);
            p[x]^=1;
        }
    }
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    REP(i,n){
        RI(p[i+1]);
    }
    st=-1;
    REP(i,n){
        if(p[i+1]==1){
            st=i+1;
            break;
        }
    }
    if(st==-1)puts("0");
    else{
        dfs(st);
        if(p[st]){
            an.pop_back();
            p[st]^=1;
        }
        REP(i,n){
            if(p[i+1]){
                puts("-1");
                return 0;
            }
        }
        printf("%d\n",SZ(an));
        REP(i,SZ(an)){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }
    return 0;
}