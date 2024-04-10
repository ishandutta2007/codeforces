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
LL ll[SIZE],rr[SIZE];
int a_ll[SIZE],a_rr[SIZE];
int main(){
    DRI(n);
    REPP(i,1,n+1)RI(a[i]);
    int now=0;
    REPP(i,1,n+1){
        now=max(now+1,a[i]);
        a_ll[i]=now;
        ll[i+1]=ll[i]+now-a[i];
    }
    now=0;
    for(int i=n;i>0;i--){
        now=max(now+1,a[i]);
        a_rr[i]=now;
        rr[i-1]=rr[i]+now-a[i];
    }
    LL an=1e18;
    REPP(i,1,n+1){
        an=min(an,ll[i]+rr[i]+max(a_ll[i],a_rr[i])-a[i]);
    }
    cout<<an<<endl;
    return 0;
}