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
const int SIZE = 1e3+10;
int e[SIZE][SIZE];
int v[SIZE];
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        e[x][y]=e[y][x]=1;
    }
    VI bfs;
    int A_A=e[1][n]^1;
    bfs.PB(1);
    MS1(v);
    v[1]=0;
    REP(i,SZ(bfs)){
        int me=bfs[i];
        REPP(j,1,n+1){
            if(e[me][j]==A_A&&v[j]==-1){
                v[j]=v[me]+1;
                bfs.PB(j);
                if(j==n){
                    printf("%d\n",v[n]);
                    return 0;
                }
            }
        }
    }
    puts("-1");
    return 0;
}