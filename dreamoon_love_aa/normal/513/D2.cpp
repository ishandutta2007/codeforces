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
int L[SIZE][2],R[SIZE][2],ma[SIZE],mi[SIZE];
vector<int>an;
void error(){
    puts("IMPOSSIBLE");
    exit(0);
}
int me;
void dfs(){
    mi[me]=max(mi[me],R[me][1]);
    mi[me]=max(mi[me],L[me][1]);
    if(mi[me]>ma[me])error();
    if(L[me][1]>=R[me][0])error();
    if(R[me][1]>ma[me])error();
    int now=me;
    me++;
    if(L[now][1]>=me){
        mi[me]=L[now][1];
        ma[me]=min(ma[now],R[now][0]-1);
        dfs();
    }
    an.PB(now);
    if(me<=mi[now]){
        mi[me]=mi[now];
        ma[me]=ma[now];
        dfs();
    }
}
int main(){
    DRII(n,c);
    REP(i,n){
        L[i][0]=R[i][0]=n;
        L[i][1]=R[i][1]=-1;
    }
    REP(i,c){
        DRII(x,y);
        x--;y--;
        if(y<=x)error();
        char s[8];
        RS(s);
        if(s[0]=='R'){
            R[x][0]=min(R[x][0],y);
            R[x][1]=max(R[x][1],y);
        }
        else{
            L[x][0]=min(L[x][0],y);
            L[x][1]=max(L[x][1],y);
        }
    }
    mi[0]=n-1;
    ma[0]=n-1;
    dfs();
    REP(i,SZ(an)){
        if(i)printf(" ");
        printf("%d",an[i]+1);
    }
    return 0;
}