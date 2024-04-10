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

int main(){
    LL n;
    cin>>n;
    if(!n)return 0*puts("0 0");
    n--;
    LL ll=0,rr=1e9;
    while(ll<rr){
        LL mm=(ll+rr+1)>>1;
        LL now=mm*(mm+1)*3+mm;
        if(now>n)rr=mm-1;
        else ll=mm;
    }
    LL x=1+ll,y=2+2*ll;
    n-=ll*(ll+1)*3+ll;
    ll++;
    {//1
        LL need=min(n,ll);
        n-=need;
        x-=need*2;
    }
    {//2
        LL need=min(n,ll);
        n-=need;
        x-=need;
        y-=need*2;
    }
    {//3
        LL need=min(n,ll);
        n-=need;
        x+=need;
        y-=need*2;
    }
    {//4
        LL need=min(n,ll);
        n-=need;
        x+=need*2;
    }
    {//5
        LL need=min(n,ll+1);
        n-=need;
        x+=need;
        y+=need*2;
    }
    {//6
        LL need=min(n,ll);
        n-=need;
        x-=need;
        y+=need*2;
    }
    cout<<x<<" "<<y;
    return 0;
}