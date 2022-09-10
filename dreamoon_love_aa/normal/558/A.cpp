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
int n;
// template end here
int x[SIZE],a[SIZE],used[SIZE],tt,an;
void go(int dir){
    tt++;
    int res=0;
    int now=0;
    REP(i,1000){
        int nxt=-1;
        REP(j,n){
            if(used[j]==tt)continue;
            if(i%2==dir){
                if(x[j]>now){
                    if(nxt==-1||x[j]<x[nxt]){
                        nxt=j;
                    }
                }
            }
            else{
                if(x[j]<now){
                    if(nxt==-1||x[j]>x[nxt]){
                        nxt=j;
                    }
                }
            }
        }
        if(nxt==-1)break;
        now=x[nxt];
        used[nxt]=tt;
        res+=a[nxt];
    }
    an=max(an,res);
}
int main(){
    RI(n);
    REP(i,n)RII(x[i],a[i]);
    go(0);
    go(1);
    printf("%d\n",an);
    return 0;
}