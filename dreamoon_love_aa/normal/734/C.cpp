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
const int INF = 2e9+7;
const int SIZE = 1e6+10;
int a[SIZE],b[SIZE],c[SIZE],d[SIZE];
int main(){
    DRIII(n,m,k);
    DRII(x,s);
    REP(i,m)RI(a[i]);
    REP(i,m)RI(b[i]);
    REP(i,k)RI(c[i]);
    REP(i,k)RI(d[i]);
    VPII v;
    REP(i,k)v.PB(MP(d[i],c[i]));
    LL an=INF*(LL)INF;
    a[m]=x,b[m]=0;
    REP(i,m+1){
        if(b[i]<=s){
            int it=upper_bound(ALL(v),MP(s-b[i],INF))-v.begin();
            if(!it){
                an=min(an,a[i]*(LL)n);
            }
            else{
                an=min(an,a[i]*(LL)max(0,n-c[it-1]));
            }
        }
    }
    cout<<an;
    return 0;
}