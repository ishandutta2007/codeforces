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
int L[5],R[5],num[5];
int inter(int x,int y){
    if(x>y)return 0;
    return y-x+1;
}
int main(){
    DRI(n);
    REP(i,n){
        RII(L[i],R[i]);
        num[i]=R[i]-L[i]+1;
    }
    long double an=0;
    REP(i,n){
        REP(j,n){
            if(i==j)continue;
            REPP(k,1,10001){
                if(k<L[j]||k>R[j])continue;
                long double p=1.*k/num[j];
                REP(k2,n){
                    if(k2==i){
                        if(i<j)p=p*inter(max(L[k2],k),R[k2])/num[k2];
                        else p=p*inter(max(L[k2],k+1),R[k2])/num[k2];
                    }
                    else if(k2<j){
                        p=p*inter(L[k2],min(k-1,R[k2]))/num[k2];
                    }
                    else if(k2>j){
                        p=p*inter(L[k2],min(k,R[k2]))/num[k2];
                    }
                }
                an+=p;
            }
        }
    }
    printf("%.12f\n",(double)an);
    return 0;
}