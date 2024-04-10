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
const int SIZE = 1e5+5;
vector<int>e,o;
vector<int>an[SIZE];
int main(){
    DRIII(n,k,p);
    REP(i,n){
        DRI(x);
        if(x&1)o.PB(x);
        else e.PB(x);
    }
    int on=k-p;
    if(on>SZ(o)||(SZ(o)-on)%2==1||(SZ(o)-on)/2+SZ(e)<p)puts("NO");
    else{
        REP(i,on)an[i].PB(o[i]);
        int now=on%k;
        for(int i=on;i<SZ(o);i+=2){
            an[now].PB(o[i]);
            an[now].PB(o[i+1]);
            now=(now+1)%k;
        }
        REP(i,SZ(e)){
            an[now].PB(e[i]);
            now=(now+1)%k;
        }
        puts("YES");
        REP(i,k){
            printf("%d",SZ(an[i]));
            REP(j,SZ(an[i])){
                printf(" %d",an[i][j]);
            }
            puts("");
        }
    }
    return 0;
}