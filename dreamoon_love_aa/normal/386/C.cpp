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
const int SIZE = 3e5+10;
LL an[27];
int nxt[SIZE][27];
char s[SIZE];
int main(){
    RS(s);
    int n=LEN(s);
    REP(i,26)nxt[n][i]=n;
    for(int i=n-1;i>=0;i--){
        REP(j,26)nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i]-'a']=i;
    }
    REP(i,n){
        nxt[i][26]=n;
        sort(nxt[i],nxt[i]+26);
        REPP(j,1,27){
            an[j]+=nxt[i][j]-nxt[i][j-1];
        }
    }
    int ma=26;
    while(!an[ma])ma--;
    printf("%d\n",ma);
    REPP(i,1,ma+1)printf("%I64d ",an[i]);
    return 0;
}