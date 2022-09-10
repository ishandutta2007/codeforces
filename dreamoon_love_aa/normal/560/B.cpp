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
bool check(int x,int y,int a1,int b1,int a2,int b2){
    return a1<=x&&a2<=x&&b1+b2<=y;
}
int main(){
    DRII(x,y);
    DRII(a1,b1);
    DRII(a2,b2);
    if(check(x,y,a1,b1,a2,b2)
     ||check(x,y,a1,b1,b2,a2)
     ||check(x,y,b1,a1,a2,b2)
     ||check(x,y,b1,a1,b2,a2)
     ||check(y,x,a1,b1,a2,b2)
     ||check(y,x,a1,b1,b2,a2)
     ||check(y,x,b1,a1,a2,b2)
     ||check(y,x,b1,a1,b2,a2))puts("YES");
    else puts("NO");
    return 0;
}