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
VPII e[SIZE];
int an[SIZE][2];
double res[SIZE];
double inv(double x){
    x+=1;
    if(x>=2)x-=2;
    return x;
}
void dfs(int x,int lt,double v){
    int num=SZ(e[x]);
    int it=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        int eid=e[x][i].S;
        double v2=(v+it*2./num);
        it++;
        if(v2>=2)v2-=2;
        if(v2<1){
            an[eid][0]=x;
            an[eid][1]=y;
            res[eid]=v2;
        }
        else{
            an[eid][0]=y;
            an[eid][1]=x;
            res[eid]=inv(v2);
        }
        dfs(y,x,inv(v2));
    }
}
int main(){
    DRI(n);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(MP(y,i));
        e[y].PB(MP(x,i));
    }
    dfs(1,1,0.049);
    printf("%d\n",n-1);
    REPP(i,1,n){
        printf("1 %d %d %d %.12f\n",i,an[i][0],an[i][1],res[i]);
    }
    return 0;
}