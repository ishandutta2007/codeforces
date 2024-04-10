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
const int SIZE = 2e3+10;
int n,m;
char s[SIZE][SIZE];
bool Out(int x,int y){return x<0||y<0||x>=n-1||y>=m-1;}
void check(int i,int j){
    if(Out(i,j))return;
    int cnt=0;
    REP(i2,2)REP(j2,2)cnt+=(s[i+i2][j+j2]=='.');
    if(cnt==3){
        REP(i2,2){
            REP(j2,2){
                s[i+i2][j+j2]='.';
            }
        }
        REPP(i2,-1,2)REPP(j2,-1,2)check(i+i2,j+j2);
    }
}
int main(){
    RII(n,m);
    REP(i,n)RS(s[i]);
    REP(i,n-1)REP(j,m-1){
        check(i,j);
    }
    REP(i,n)puts(s[i]);
    return 0;
}