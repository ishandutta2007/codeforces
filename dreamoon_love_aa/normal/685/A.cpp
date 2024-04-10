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
int f(int x){
    int res=0;
    while(x){
        x/=7;
        res++;
    }
    return max(1,res);
}
int main(){
    DRII(n,m);
    n--;m--;
    int all=f(n)+f(m);
    if(all>7)return 0*puts("0");
    int x=f(n),y=f(m);
    n++;m++;
    int an=0;
    REP(i,n)REP(j,m){
        int a=i,b=j;
        bool used[7]={},suc=1;
        REP(k,x){
            if(used[a%7])suc=0;
            used[a%7]=1;
            a/=7;
        }
        REP(k,y){
            if(used[b%7])suc=0;
            used[b%7]=1;
            b/=7;
        }
        if(suc)an++;
    }
    printf("%d\n",an);
    return 0;
}