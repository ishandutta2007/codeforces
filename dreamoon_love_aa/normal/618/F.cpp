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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],b[SIZE];
PII dif[SIZE*2];
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i+1]);
    }
    REP(i,n){
        RI(b[i+1]);
    }
    REP(i,SIZE*2)dif[i]=MP(INF,INF);
    dif[SIZE]=MP(1,1);
    int a_it=1,b_it=1;
    int now=0;
    while(1){
        if(now<=0){
            now+=a[a_it++];
        }
        else{
            now-=b[b_it++];
        }
        if(dif[now+SIZE].F!=INF){
            printf("%d\n",a_it-dif[now+SIZE].F);
            REPP(i,dif[now+SIZE].F,a_it)printf("%d ",i);
            puts("");
            printf("%d\n",b_it-dif[now+SIZE].S);
            REPP(i,dif[now+SIZE].S,b_it)printf("%d ",i);
            puts("");
            return 0;
        }
        dif[now+SIZE]=MP(a_it,b_it);
    }
    return 0;
}