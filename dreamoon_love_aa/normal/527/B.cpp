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
int d[128][128];
int main(){
    string S,T;
    DRI(n);
    cin>>S>>T;
    int an=0;
    REP(i,n){
        if(S[i]!=T[i]){
            an++;
            d[S[i]][T[i]]=i+1;
        }
    }
    REPP(i,'a','z'+1)REPP(j,i,'z'+1){
        if(d[i][j]&&d[j][i]){
            printf("%d\n",an-2);
            printf("%d %d\n",d[i][j],d[j][i]);
            return 0;
        }
    }
    REPP(i,'a','z'+1){
        char x='a';
        char y='a';
        while(x<='z'&&!d[i][x])x++;
        while(y<='z'&&!d[y][i])y++;
        if(x<='z'&&y<='z'){
            printf("%d\n",an-1);
            printf("%d %d\n",d[i][x],d[y][i]);
            return 0;
        }
    }
    printf("%d\n-1 -1\n",an);
    return 0;
}