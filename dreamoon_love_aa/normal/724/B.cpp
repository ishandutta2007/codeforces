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
VI a[24];
int can[24][24][24];
VPII pp;
int main(){
    VI good;
    DRII(n,m);
    REP(i,m)good.PB(i);
    REP(i,n)REP(j,m){
        DRI(x);x--;
        a[i].PB(x);
    }
    REP(i,m)REPP(j,i+1,m)pp.PB(MP(i,j));
    REP(i,n){
        if(a[i]==good){
            REP(j,m)REP(k,m)can[i][j][k]=1;
            continue;
        }
        REP(j,SZ(pp)){
            swap(a[i][pp[j].F],a[i][pp[j].S]);
            if(a[i]==good){
                can[i][0][0]=1;
                can[i][pp[j].F][pp[j].S]=1;
            }
            swap(a[i][pp[j].F],a[i][pp[j].S]);
        }
        REP(j,SZ(pp)){
            swap(a[i][pp[j].F],a[i][pp[j].S]);
            REP(k,SZ(pp)){
                swap(a[i][pp[k].F],a[i][pp[k].S]);
                if(a[i]==good){
                    can[i][pp[j].F][pp[j].S]=1;
                    can[i][pp[k].F][pp[k].S]=1;
                }
                swap(a[i][pp[k].F],a[i][pp[k].S]);
            }
            swap(a[i][pp[j].F],a[i][pp[j].S]);
        }
    }
    REP(i,m)REP(j,m){
        int cnt=0;
        REP(k,n)cnt+=can[k][i][j];
        if(cnt==n)return 0*puts("YES");
    }
    puts("NO");
    return 0;
}