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
const int SIZE = 5000;
int a[SIZE],b[SIZE];
int qq(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    DRI(v);
    return v;
}
int main(){
    DRI(n);
    int y=-1;
    REP(i,n){
        a[i]=qq(0,i);
        if(a[i]==0)y=i;
    }
    REP(i,n){
        b[i]=qq(i,y);
    }
    VI p;
    REP(i,n){
        bool suc=1;
        REP(x,n){
            y=i^b[x];
            if((a[y]^i)!=x){
                suc=0;
                break;
            }
        }
        if(suc)p.PB(i);
    }
    printf("!\n%d\n",SZ(p));
    fflush(stdout);
    REP(i,n){
        printf("%d%c",b[i]^p[0]," \n"[i==n-1]);
    }
    return 0;
}