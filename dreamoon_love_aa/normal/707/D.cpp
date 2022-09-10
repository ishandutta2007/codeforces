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
const int SIZE = 1e5+10;
int lt[SIZE],lv[SIZE],num[SIZE];
int qq[SIZE][2],ty[SIZE];
int len[5]={0,2,2,1,1};
bitset<1001>d[1001],rev;
VI e[SIZE];
int an[SIZE],m;
void dfs(int x,int v){
    an[x]=v;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        int me;
        if(ty[y]==1){
            me=d[qq[y][0]][qq[y][1]];
            d[qq[y][0]][qq[y][1]]=1;
            dfs(y,v+1-me);
            d[qq[y][0]][qq[y][1]]=me;
        }
        else if(ty[y]==2){
            me=d[qq[y][0]][qq[y][1]];
            d[qq[y][0]][qq[y][1]]=0;
            dfs(y,v-me);
            d[qq[y][0]][qq[y][1]]=me;
        }
        else if(ty[y]==3){
            int cnt=d[qq[y][0]].count();
            d[qq[y][0]]^=rev;
            dfs(y,v-cnt+(m-cnt));
            d[qq[y][0]]^=rev;
        }
        else dfs(y,v);

    }
}
int main(){
    int n,q;
    RIII(n,m,q);
    REP(i,m)rev[i+1]=1;
    REPP(i,1,q+1){
        RI(ty[i]);
        REP(j,len[ty[i]])RI(qq[i][j]);
        if(ty[i]!=4)e[i-1].PB(i);
        else e[qq[i][0]].PB(i);
    }
    dfs(0,0);
    REP(i,q)printf("%d\n",an[i+1]);
    return 0;
}