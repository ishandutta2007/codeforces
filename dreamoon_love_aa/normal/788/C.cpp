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
const int SIZE = 2e6+10;
bitset<SIZE> ker;
bitset<1001>have;
int v[SIZE];
int bfs[SIZE];
VI e;
int main(){
    DRII(n,k);
    bool small=0,big=0;
    REP(i,k){
        DRI(x);
        if(x==n)return 0*puts("1");
        if(x<n)small=1;
        else big=1;
        have[x]=1;
    }
    if(!small||!big)return 0*puts("-1");
    REP(i,1001){
        if(have[i])e.PB(i-n);
    }
    int MID=SIZE/2;
    ker[MID]=1;
    bfs[0]=MID;
    int rr=1;
    REP(i,rr){
        int me=bfs[i];
        REP(j,SZ(e)){
            int nxt=me+e[j];
            if(nxt==MID)return 0*printf("%d\n",v[me]+1);
            if(!ker[nxt]){
                ker[nxt]=1;
                v[nxt]=v[me]+1;
                bfs[rr++]=nxt;
            }
        }
    }
    return 0;
}