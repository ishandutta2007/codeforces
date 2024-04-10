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
int main(){
    DRII(x1,y1);
    DRII(x2,y2);
    while(1){
        //printf("(%d,%d)-(%d,%d)\n",x1,y1,x2,y2);
        if((x1-x2)>=(y1-y2)&&x1&&(x1-1!=x2||y1!=y2)){
            x1--;
        }
        else y1--;
        if(!(x1+y1)){
            puts("Polycarp");
            return 0;
        }
        if((x1+1!=x2||y1+1!=y2)&&x2&&y2){
            x2--;
            y2--;
        }
        else if((x1+1!=x2||y1!=y2)&&x2){
            x2--;
        }
        else{
            y2--;
        }
        if(!(x2+y2)){
            puts("Vasiliy");
            return 0;
        }
    }
    return 0;
}