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
int a[SIZE];
int main(){
    DRII(n,k);
    int four=n,two=n*2;
    REP(i,k){
        RI(a[i]);
        while(a[i]>=4&&four>0){
            four--;
            a[i]-=4;
        }
    }
    REP(i,k){
        while(a[i]>=2&&two>0){
            two--;
            a[i]-=2;
        }
    }
    int twotwo=0,oneone=0;
    REP(i,k){
        while(a[i]>=2){
            twotwo++;
            a[i]-=2;
        }
        oneone+=a[i];
    }
    while(twotwo>0&&oneone>0&&four>0){
        four--;twotwo--;oneone--;
    }
    while(four>=2&&twotwo>=3){
        four-=2;
        twotwo-=3;
    }
    while(four>0&&twotwo>0){
        four--;
        twotwo--;
    }
    while(four>0&&oneone>0){
        four--;
        oneone-=2;
    }
    while(two>0&&oneone>0){
        two--;
        oneone--;
    }
    puts((oneone>0||twotwo>0)?"NO":"YES");
    return 0;
}