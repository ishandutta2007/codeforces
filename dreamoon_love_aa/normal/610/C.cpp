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
const int SIZE = 1e6+10;
char an[1024][1024];
void f(int lv,int ng,int x1,int y1,int x2,int y2){
    if(lv==1){
        an[x1][y1]=1^ng;
        an[x1][y2]=1^ng;
        an[x2][y1]=1^ng;
        an[x2][y2]=ng;
        return;
    }
    int mx=(x1+x2)/2;
    int my=(y1+y2)/2;
    f(lv-1,ng,x1,y1,mx,my);
    f(lv-1,ng,mx+1,y1,x2,my);
    f(lv-1,1^ng,x1,my+1,mx,y2);
    f(lv-1,ng,mx+1,my+1,x2,y2);
}
int main(){
    DRI(n);
    if(n==0){
        puts("+");
    }
    else{
        f(n,0,0,0,(1<<n)-1,(1<<n)-1);
        REP(i,1<<n){
            REP(j,1<<n)printf("%c",an[i][j]?'+':'*');
            puts("");
        }
    }
    return 0;
}