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
int d[2][3000][3000],ee[3000][3000];
vector<int>e[3000],ae[3000];
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);x--;y--;
        e[x].PB(y);
        ae[y].PB(x);
        ee[x][y]=1;
    }
    LL an=0;
    REP(i,n){
        REP(j,SZ(e[i]))REP(k,j){
            int x=e[i][j];
            int y=e[i][k];
            if(ee[x][i]&&ee[y][i])an--;
            if(x>y)swap(x,y);
            d[0][x][y]++;
        }
    }
    REP(i,n){
        REP(j,SZ(ae[i]))REP(k,j){
            int x=ae[i][j];
            int y=ae[i][k];
            if(x>y)swap(x,y);
            d[1][x][y]++;
        }
    }
    REP(i,n)REP(j,i)an+=d[0][j][i]*d[1][j][i];
    cout<<an;
    return 0;
}