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
const int SIZE = 2e5+10;
LL b[SIZE],c[SIZE],s[SIZE],a[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        DRI(x);
        b[i]=x;
    }
    REP(i,n){
        DRI(x);
        c[i]=x;
    }
    LL sum=0;
    REP(i,n)
        sum+=s[i]=b[i]+c[i];
    if(sum%(2*n))return 0*puts("-1");
    sum/=2*n;
    LL bit[30]={};
    REP(i,n){
        LL v=s[i]-sum;
        if(v%n||v<0)return 0*puts("-1");
        v/=n;
        a[i]=v;
        REP(j,30){
            if((v>>j)&1)bit[j]++;
        }
    }
    REP(i,n){
        LL bb=0,cc=0;
        REP(j,30){
            if((a[i]>>j)&1){
                bb+=bit[j]<<j;
                cc+=(LL)n<<j;
            }
            else{
                cc+=bit[j]<<j;
            }
        }
        if(bb!=b[i]||cc!=c[i])
            return 0*puts("-1");
    }
    REP(i,n)printf("%I64d%c",a[i]," \n"[i==n-1]);
    return 0;
}