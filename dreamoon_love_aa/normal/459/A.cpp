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
// template end here

int main(){
    int x[2],y[2];
    int xx,yy;
    RII(x[0],y[0]);
    RII(x[1],y[1]);
    xx=x[0];
    yy=y[0];
    sort(x,x+2);
    sort(y,y+2);
    if(x[0]==x[1]){
        int w=y[1]-y[0];
        printf("%d %d %d %d\n",x[0]+w,y[0],x[0]+w,y[1]);
    }
    else if(y[0]==y[1]){
        int w=x[1]-x[0];
        printf("%d %d %d %d\n",x[0],y[0]+w,x[1],y[1]+w);
    }
    else{
        if(x[1]-x[0]!=y[1]-y[0])puts("-1");
        else{
            printf("%d %d %d %d\n",xx,y[0]+y[1]-yy,x[0]+x[1]-xx,yy);
        }
    }
    return 0;
}