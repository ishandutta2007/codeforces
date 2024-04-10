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
const int SIZE = 1501;
int x[SIZE],y[SIZE],r[SIZE];
VI e[SIZE];
int lv[SIZE];
LL sqr(LL x){return x*x;}
//id1 in id2
bool in(int id1,int id2){
    if(r[id1]>=r[id2])return 0;
    return sqr(y[id1]-y[id2])+sqr(x[id1]-x[id2])<=sqr(r[id2]);

}
LL dp[SIZE][4];

template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void dfs(int x){
    REP(i,4)dp[x][i]=-INF;
    if(SZ(e[x])==0){
        dp[x][0]=-sqr(r[x]);
        dp[x][1]=sqr(r[x]);
        dp[x][2]=sqr(r[x]);
        dp[x][3]=sqr(r[x]);
        return;
    }
    LL tmp[4][2]={};
    LL v=sqr(r[x]);
    tmp[0][0]=-v;
    tmp[0][1]=-v;
    tmp[1][0]=v;
    tmp[1][1]=-v;
    tmp[2][0]=-v;
    tmp[2][1]=v;
    tmp[3][0]=v;
    tmp[3][1]=v;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        dfs(y);
        tmp[0][0]+=dp[y][1];
        tmp[0][1]+=dp[y][2];
        tmp[1][0]+=dp[y][0];
        tmp[1][1]+=dp[y][3];
        tmp[2][0]+=dp[y][3];
        tmp[2][1]+=dp[y][0];
        tmp[3][0]+=dp[y][2];
        tmp[3][1]+=dp[y][1];
    }
    REP(i,4)dp[x][i]=max(tmp[i][0],tmp[i][1]);
}
LL go(int x){
    dfs(x);
    return dp[x][3];
}
int main(){
    DRI(n);
    REP(i,n){
        RIII(x[i],y[i],r[i]);
    }
    REP(i,n)REP(j,n){
        if(i==j)continue;
        if(in(i,j)){
            lv[i]++;
        }
    }
    REP(i,n)REP(j,n){
        if(i==j)continue;
        if(in(i,j)&&lv[i]==lv[j]+1)e[j].PB(i);
    }
    LL an=0;
    REP(i,n){
        if(lv[i]==0)an+=go(i);
    }
    printf("%.8f\n",an*acos(-1));
    return 0;
}