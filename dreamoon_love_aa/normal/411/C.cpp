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
int a[4][2];
int main(){
    REP(i,4)REP(j,2)RI(a[i][j]);
    if(a[0][1]>max(a[2][0],a[3][0])&&a[1][0]>max(a[2][1],a[3][1]))puts("Team 1");
    else if(a[1][1]>max(a[2][0],a[3][0])&&a[0][0]>max(a[2][1],a[3][1]))puts("Team 1");
    else if((a[0][1]>=a[2][0]||a[1][0]>=a[3][1])&&(a[0][1]>=a[3][0]||a[1][0]>=a[2][1]))puts("Draw");
    else if((a[1][1]>=a[2][0]||a[0][0]>=a[3][1])&&(a[1][1]>=a[3][0]||a[0][0]>=a[2][1]))puts("Draw");
    else puts("Team 2");
    return 0;
}