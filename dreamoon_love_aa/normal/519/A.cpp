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
char s[22];
int main(){
    int A=0,B=0;
    REP(i,8){
        RS(s);
        REP(j,8){
            if(s[j]=='Q')A+=9;
            else if(s[j]=='q')B+=9;
            else if(s[j]=='R')A+=5;
            else if(s[j]=='r')B+=5;
            else if(s[j]=='B')A+=3;
            else if(s[j]=='b')B+=3;
            else if(s[j]=='N')A+=3;
            else if(s[j]=='n')B+=3;
            else if(s[j]=='P')A+=1;
            else if(s[j]=='p')B+=1;
        }
    }
    if(A>B)puts("White");
    else if(A<B)puts("Black");
    else puts("Draw");
    return 0;
}