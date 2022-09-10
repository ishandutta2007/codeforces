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
#define F first
#define S second
typedef long long LL;
using namespace std;
int main(){
    CASET{
        LL n,k,d1,d2;
        cin>>n>>k>>d1>>d2;
        if(n%3)puts("no");
        else{
            bool suc=false;
            if(k-(d1*2+d2)>=0&&(k-(d1*2+d2))%3==0){
                if((k-(d1*2+d2))/3+d1+d2<=n/3)suc=true;
            }
            if(k-(d1+d2)>=0&&(k-d1-d2)%3==0){
                if((k-d1-d2)/3+max(d1,d2)<=n/3)suc=true;
            }
            if((k+(d1+d2))%3==0&&(k+d1+d2)/3-max(d1,d2)>=0){
                if((k+d1+d2)/3<=n/3)suc=true;
            }
            if(k-(d2*2+d1)>=0&&(k-(d2*2+d1))%3==0){
                if((k-(d2*2+d1))/3+d1+d2<=n/3)suc=true;
            }
            puts(suc?"yes":"no");
        }
    }
    return 0;
}