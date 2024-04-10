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

int main(){
    CASET{
        DRI(n);
        VI d[2];
        REPP(i,1,n+1){
            if(i+1>n)break;
            printf("? %d %d\n",i,i+1);
            fflush(stdout);
            char s[4];
            RS(s);
            if(s[0]=='>'){d[1].PB(i);d[0].PB(i+1);}
            else{d[1].PB(i+1);d[0].PB(i);}
            i++;
        }
        if(n%2==1){d[0].PB(n);d[1].PB(n);}
        REPP(i,1,SZ(d[0])){
            printf("? %d %d\n",d[0][i],d[0][i-1]);
            fflush(stdout);
            char s[4];
            RS(s);
            if(s[0]=='>')d[0][i]=d[0][i-1];
        }
        REPP(i,1,SZ(d[1])){
            printf("? %d %d\n",d[1][i],d[1][i-1]);
            fflush(stdout);
            char s[4];
            RS(s);
            if(s[0]=='<')d[1][i]=d[1][i-1];
        }
        printf("! %d %d\n",d[0].back(),d[1].back());
        fflush(stdout);
    }
    return 0;
}