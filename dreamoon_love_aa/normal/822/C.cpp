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
VPLL len[SIZE];
int an=-1;
void solve(int v1,int v2){
    int it=0;
    LL mi=2.1e9;
    LL now=2.05e9;
    REP(i,SZ(len[v1])){
        while(it<SZ(len[v2])&&len[v2][it].F+v2<=len[v1][i].F){
            now=min(now,len[v2][it].S);
            it++;
        }
        mi=min(mi,(LL)now+len[v1][i].S);
    }
    if(mi>2000000000)return;
    if(an==-1||an>mi)an=mi;
}
int main(){
    DRII(n,x);
    REP(i,n){
        DRIII(x,y,v);
        len[y-x+1].PB(MP(x,v));
    }
    REPP(i,1,x+1)sort(ALL(len[i]));
    for(int i=1;i<x;i++){
        int j=x-i;
        solve(i,j);
    }
    printf("%d\n",an);
    return 0;
}