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
#define VL vector<long long>
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
    DRI(n);
    int an=0;
    int v=0;
    int overtake=0;
    VI speed_stk;
    REP(i,n){
        DRI(ty);
        if(ty==1){
            RI(v);
            while(SZ(speed_stk)&&speed_stk.back()<v){
                an++;
                speed_stk.pop_back();
            }
        }
        else if(ty==2){
            an+=overtake;
            overtake=0;
        }
        else if(ty==3){
            DRI(x);
            if(x<v)an++;
            else speed_stk.PB(x);
        }
        else if(ty==4){
            overtake=0;
        }
        else if(ty==5){
            speed_stk.clear();
        }
        else{
            overtake++;
        }
    }
    return 0*printf("%d\n",an);
}