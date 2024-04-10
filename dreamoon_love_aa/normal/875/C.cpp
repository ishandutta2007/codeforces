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
VI d[SIZE];
int H[SIZE];
bool greaterr(int x,int y){
    if(H[x]!=H[y]){
        return H[x]<H[y];
    }
    return x>y;
}
VI e[SIZE];
VI bfs;
int ban[SIZE];
void add_edge(int x,int y){
    if(x<y){
        e[y].PB(x);
    }
    else{
        H[x]=1;
        bfs.PB(x);
        ban[y]=1;
    }
}
bool build(int L,int R,int lv){
    int lt=-1;
    for(int i=L,j;i<=R;i=j){
        if(lt!=-1)add_edge(lt,d[i][lv]);
        lt=d[i][lv];
        for(j=i+1;j<=R&&d[j][lv]==d[i][lv];j++);
        int st=i;
        for(;st<j&&SZ(d[st])==lv+1;st++);
        REPP(k,st,j)
            if(SZ(d[k])==lv+1)return 0;
        if(st<j&&!build(st,j-1,lv+1))return 0;
    }
    return 1;
}
bool gg(VI& d1,VI& d2){
    int bb=min(SZ(d1),SZ(d2));
    REP(i,bb){
        if(d1[i]!=d2[i]){
            if(greaterr(d1[i],d2[i]))return 1;
            return 0;
        }
    }
    return SZ(d1)>SZ(d2);
}
int main(){
    DRII(N,M);
    REP(i,N){
        DRI(m);
        while(m--){
            DRI(x);
            d[i].PB(x);
        }
    }
    if(!build(0,N-1,0)){
        puts("No");
        return 0;
    }
    REPP(i,1,M+1){
        if(H[i]&&ban[i]){
            puts("No");
            return 0;
        }
    }
    REP(i,SZ(bfs)){
        int x=bfs[i];
        REP(j,SZ(e[x])){
            int y=e[x][j];
            if(H[y])continue;
            if(ban[y])return 0*puts("No");
            H[y]=1;
            bfs.PB(y);
        }
    }
    VI an;
    REPP(i,1,M+1){
        if(H[i])an.PB(i);
    }
    REPP(i,1,N){
        if(gg(d[i-1],d[i])){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    printf("%d\n",SZ(an));
    REP(i,SZ(an))printf("%d ",an[i]);
    return 0;
}