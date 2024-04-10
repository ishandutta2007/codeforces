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
#define F first
#define S second
typedef long long LL;
using namespace std;
vector<pair<int,int> >pp;
int main(){
    DRIII(n,m,k);
    REPP(i,1,n+1){
        if(i%2==1){
            REPP(j,1,m+1)pp.PB(MP(i,j));
        }
        else{
            for(int j=m;j>0;j--)pp.PB(MP(i,j));
        }
    }
    int now=0;
    REP(i,k-1){
        printf("2");
        printf(" %d %d",pp[now].F,pp[now].S);
        now++;
        printf(" %d %d",pp[now].F,pp[now].S);
        now++;
        puts("");
    }
    printf("%d",SZ(pp)-now);
    REPP(i,now,SZ(pp)){
        printf(" %d %d",pp[i].F,pp[i].S);
    }
    puts("");
    return 0;
}