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
int H[2],W[2];
int main(){
    DRI(C);
    REP(i,2)RI(H[i]);
    REP(i,2)RI(W[i]);
    if(W[0]<W[1]){
        swap(W[0],W[1]);
        swap(H[0],H[1]);
    }
    if(W[0]>1000){
        LL an=0;
        for(int i=0;i*W[0]<=C;i++){
            an=max(an,(LL)i*H[0]+(LL)((C-i*W[0])/W[1])*H[1]);
        }
        cout<<an<<endl;
    }
    else{
        LL an=0;
        REP(i,100000){
            REP(j,2){
                if((LL)W[j]*i<=C){
                    an=max(an,(LL)i*H[j]+(LL)((C-i*W[j])/W[j^1])*H[j^1]);
                }
            }
        }
        cout<<an<<endl;
    }
    return 0;
}