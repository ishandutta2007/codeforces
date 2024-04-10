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
int x[SIZE],y[SIZE],d[SIZE],dn;
int main(){
    DRII(m,K);
    REP(i,m){
        RII(x[i],y[i]);
        d[dn++]=x[i];
        d[dn++]=y[i];
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REP(i,dn){
        printf("%d:",d[i]);
        VI me;
        REP(j,m)
            if(x[j]==d[i]||y[j]==d[i])me.PB(x[j]+y[j]-d[i]);
        sort(ALL(me));
        VI res;
        REP(j,dn){
            if(i==j)continue;
            if(binary_search(ALL(me),d[j]))continue;
            int cnt=0;
            REP(k,m){
                if(x[k]==d[j]||y[k]==d[j]){
                    if(binary_search(ALL(me),x[k]+y[k]-d[j]))cnt++;
                }
            }
            if(cnt*100>=K*SZ(me))res.PB(d[j]);
        }
        printf(" %d",SZ(res));
        REP(j,SZ(res))printf(" %d",res[j]);
        puts("");
    }
    return 0;
}