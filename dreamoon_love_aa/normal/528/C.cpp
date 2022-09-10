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
VPII e[SIZE];
int used[SIZE],tt;
int one[SIZE],on;
int en;
int it[SIZE];
int ty;
void dfs3(int x){
    while(it[x]<SZ(e[x])){
        if(used[e[x][it[x]].S]!=tt){
            used[e[x][it[x]].S]=tt;
            int me=e[x][it[x]].F;
            it[x]++;
            dfs3(me);
            if(ty)printf("%d %d\n",x,me);
            else printf("%d %d\n",me,x);
            ty^=1;
        }
        else it[x]++;
    }
}
void dfs2(int x){
    en+=SZ(e[x]);
    used[x]=tt;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(used[y]==tt)continue;
        dfs2(y);
    }
}
void dfs(int x){
    if(SZ(e[x])&1)one[on++]=x;
    used[x]=tt;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(used[y]==tt)continue;
        dfs(y);
    }
}
int main(){
    int n,m;
    while(RII(n,m)==2){
        //part1
        tt++;
        REP(i,m){
            DRII(x,y);
            e[x].PB(MP(y,i));
            e[y].PB(MP(x,i));
        }
        REPP(i,1,n+1){
            if(used[i]!=tt){
                dfs(i);
            }
        }
        one[on]=one[0];
        for(int i=1;i<=on;i+=2){
            e[one[i]].PB(MP(one[i+1],m));
            e[one[i+1]].PB(MP(one[i],m));
            m++;
        }
        //part2
        tt++;
        REPP(i,1,n+1){
            if(used[i]!=tt){
                en=0;
                dfs2(i);
                if((en/2)%2==1){
                    e[i].PB(MP(i,m));
                    m++;
                }
            }
        }
        //part3
        printf("%d\n",m);
        tt++;
        REPP(i,1,n+1){
            if(used[i]!=tt){
                dfs3(i);
            }
        }
    }
}