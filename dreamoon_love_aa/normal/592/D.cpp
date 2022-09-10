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
const int SIZE = 123457;
bool sp[SIZE];
vector<pair<int,int> >e[SIZE];
int NUM;
int dp[SIZE][2],far[SIZE];
bool dfs1(int x,int lt){
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(dfs1(y,x))sp[x]=1;
        if(dp[y][0]+e[x][i].S>dp[x][0]){
            dp[x][1]=dp[x][0];
            dp[x][0]=dp[y][0]+e[x][i].S;
        }
        else if(dp[y][0]+e[x][i].S>dp[x][1]){
            dp[x][1]=dp[y][0]+e[x][i].S;
        }
    }
    if(!sp[x])dp[x][0]=dp[x][1]=-1;
    else NUM++;
    return sp[x];
}
int MA,AN;
void dfs2(int x,int lt,int v){
    if(!sp[x])return;
    far[x]=max(v,dp[x][0]);
    if(far[x]>MA||(far[x]==MA&&AN>x)){
        MA=far[x];
        AN=x;
    }
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(dp[y][0]+e[x][i].S==dp[x][0])dfs2(y,x,max(v,dp[x][1])+e[x][i].S);
        else dfs2(y,x,max(v,dp[x][0])+e[x][i].S);
    }
}
int main(){
    DRII(n,m);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(MP(y,1));
        e[y].PB(MP(x,1));
    }
    if(n==1){
        puts("1 0");
        return 0;
    }
    int root;
    REP(i,m){
        DRI(x);
        root=x;
        sp[x]=1;
    }
    dfs1(root,root);
    AN=1e9;
    dfs2(root,root,0);
    printf("%d\n%d\n",AN,NUM*2-2-MA);
    return 0;
}