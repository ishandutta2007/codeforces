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
const int SIZE = 1e3+10;
char s[SIZE][SIZE],an[SIZE][SIZE];
int cnt[SIZE][SIZE],n;
VPII me,you;
bool Out(int x,int y){
    return x<0||y<0||x>=n||y>=n;
}
int main(){
    RI(n);
    REP(i,n)RS(s[i]);
    REP(i,n)REP(j,n){
        if(s[i][j]=='o'){
            me.PB(MP(i,j));
            you.PB(MP(i,j));
        }
        else if(s[i][j]=='x'){
            you.PB(MP(i,j));
        }
    }
    REPP(i,-n,2*n)REPP(j,-n,2*n)if(Out(i,j))you.PB(MP(i,j));
    REP(i,n*2-1)REP(j,n*2-1)an[i][j]='.';
    an[n-1][n-1]='o';
    REP(i,SZ(me))REP(j,SZ(you)){
        if(me[i]==you[j])continue;
        if(!Out(abs(you[j].F-me[i].F),abs(you[j].S-me[i].S)))
            cnt[n-1+you[j].F-me[i].F][n-1+you[j].S-me[i].S]++;
    }
    REP(i,2*n)REP(j,2*n){
        if(cnt[i][j]==SZ(me)){
            an[i][j]='x';
            REP(k,SZ(me))if(!Out(me[k].F+i-(n-1),me[k].S+j-(n-1))){
                s[me[k].F+i-(n-1)][me[k].S+j-(n-1)]='o';
            }
        }
    }
    REP(i,n)REP(j,n)if(s[i][j]=='x'){
        puts("NO");
        return 0;
    }
    puts("YES");
    REP(i,n*2-1)puts(an[i]);
    return 0;
}