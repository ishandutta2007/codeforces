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
// template end here
char s[1000][1000];
int main(){
    DRII(n,m);
    if(n==3&&m==2){
        puts(">vv");
        puts("^<.");
        puts(">.<");
        puts("1 3");
    }
    else if(n==5){
        puts(">.>.v");
        puts("v.<..");
        puts(">...v");
        puts(">.^..");
        puts("^.<.<");
        puts("1 1");
    }
    else{
        REP(i,n)REP(j,n)s[i][j]='.';
        REP(i,n/2+1)s[0][i]='>';
        for(int i=n/2+2;i<n-1;i+=2)s[0][i]='>';
        s[0][n-1]='v';
        REPP(i,1,n-1){
            if(i&1){
                REP(j,n/2)s[i][n-1-j]='<';
                for(int j=n-1-n/2-1;j>1;j-=2)s[i][j]='<';
                s[i][1]='v';
            }
            else{
                REP(j,n/2)s[i][1+j]='>';
                for(int j=1+n/2+1;j<n-1;j+=2)s[i][j]='>';
                s[i][n-1]='v';
            }
        }
        REP(j,n/2)s[n-1][n-1-j]='<';
        for(int j=n-1-n/2-1;j>0;j-=2)s[n-1][j]='<';
        s[n-1][0]='^';
        REP(j,n/2)s[n-2-j][0]='^';
        for(int j=n-3-n/2;j>0;j-=2)s[j][0]='^';
        REP(i,n)puts(s[i]);
        puts("1 1");
    }
    return 0;
}