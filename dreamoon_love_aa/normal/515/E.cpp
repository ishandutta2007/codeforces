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
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 4e5+10;
int d[SIZE],h[SIZE];
pair<LL,int> W[2][19][SIZE][2];
int two[SIZE];
pair<LL,int> INF=MP(-1e18,-1);
void fresh(pair<LL,int> target[],pair<LL,int> v){
    if(v.S==target[0].S||v.S==target[1].S)return;
    if(v.F>target[0].F){
        target[1]=target[0];
        target[0]=v;
    }
    else if(v.F>target[1].F){
        target[1]=v;
    }
}
LL query(int x,int y){
    pair<LL,int>res[2][2];
    int lv=two[y-x+1];
    REP(i,2){
        REP(j,2)res[i][j]=W[i][lv][x][j];
        REP(j,2)fresh(res[i],W[i][lv][y-(1<<lv)+1][j]);
    }
    if(res[0][0].S!=res[1][0].S)return res[0][0].F+res[1][0].F;
    return max(res[0][0].F+res[1][1].F,res[0][1].F+res[1][0].F);
}
int main(){
    REP(i,19)two[1<<i]=i;
    REPP(i,1,SIZE)
        if(!two[i])two[i]=two[i-1];
    DRII(n,m);
    REP(i,n){
        RI(d[i]);
        d[i+n]=d[i];
    }
    REP(i,n){
        RI(h[i]);
        h[i+n]=h[i];
    }
    LL now=0;
    REP(i,n*2){
        W[0][0][i][0]=MP(now+h[i]*2,i);
        W[1][0][i][0]=MP(-now+h[i]*2,i);
        W[0][0][i][1]=W[1][0][i][1]=INF;
        now+=d[i];
    }
    REP(j,2){
        REPP(i,1,19){
            REP(k,n*2){
                REP(k2,2)W[j][i][k][k2]=W[j][i-1][k][k2];
                if(k+(1<<(i-1))<n*2){
                    fresh(W[j][i][k],W[j][i-1][k+(1<<(i-1))][0]);
                    fresh(W[j][i][k],W[j][i-1][k+(1<<(i-1))][1]);
                }
            }
        }
    }
    while(m--){
        DRII(x,y);
        x--;y--;
        int rx=(y+1)%n;
        int ry=(x-1+n)%n;
        if(ry<rx)ry+=n;
        printf("%I64d\n",query(rx,ry));
    }
    return 0;
}