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
const int SIZE = 1e6+10;
int far[SIZE],ma1[SIZE],ma2[SIZE],an[SIZE];
int get(int n){
    memset(ma1,0,sizeof(int)*(n+1));
    memset(ma2,0,sizeof(int)*(n+1));
    for(int i=n;i>1;i--){
        int now=max(ma1[i],ma2[i]+1);
        int y=far[i];
        if(now>ma1[y]){
            ma2[y]=ma1[y];
            ma1[y]=now;
        }
        else if(now>ma2[y]){
            ma2[y]=now;
        }
    }
    return ma1[1];
}
void go(int L,int R){
    if(L+1>=R)return;
    int mm=(L+R)>>1;
    an[mm]=get(mm);
    if(an[L]==an[mm])REPP(i,L+1,mm)an[i]=an[L];
    else go(L,mm);
    if(an[mm]==an[R])REPP(i,mm+1,R)an[i]=an[R];
    else go(mm,R);
}
int main(){
    DRI(n);
    REPP(i,2,n+2){
        RI(far[i]);
    }
    an[n+1]=get(n+1);
    an[2]=1;
    go(2,n+1);
    REPP(i,2,n+2){
        if(i!=2)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}