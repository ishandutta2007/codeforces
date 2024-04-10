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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
int c[SIZE],v[SIZE],g[SIZE];
int main(){
    DRII(n,k);
    DRII(s,t);
    REP(i,n)RII(c[i],v[i]);
    REPP(i,1,k+1)RI(g[i]);
    sort(g+1,g+1+k);
    g[k+1]=s;
    int ll=1,rr=INF;
    while(ll<rr){
        int mm=(ll+rr)/2;
        LL need=0;
        REP(i,k+1){
            int dd=g[i+1]-g[i];
            if(dd>mm){
                need=t+1;
                break;
            }
            need+=dd*2-min(mm-dd,dd);
            if(need>t)break;
        }
        if(need>t)ll=mm+1;
        else rr=mm;
    }
    int an=-1;
    REP(i,n){
        if(v[i]>=ll){
            if(an==-1||an>c[i])an=c[i];
        }
    }
    printf("%d\n",an);
    return 0;
}