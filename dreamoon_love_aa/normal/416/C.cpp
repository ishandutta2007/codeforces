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
PII pp[SIZE],a[SIZE];
bool used[SIZE];
int main(){
    DRI(n);
    REP(i,n)
        RII(pp[i].F,pp[i].S);
    DRI(m);
    REP(i,m){
        RI(a[i].F);
        a[i].S=i+1;
    }
    sort(a,a+m);
    priority_queue<PII>hq;
    int it=n-1;
    int an=0;
    VPII res;
    REP(i,m){
        REP(j,n){
            if(used[j])continue;
            if(pp[j].F<=a[i].F){
                used[j]=1;
                hq.push(MP(pp[j].S,j+1));
            }
        }
        if(!hq.empty()){
            an+=hq.top().F;
            res.PB(MP(hq.top().S,a[i].S));
            hq.pop();
        }
    }
    printf("%d %d\n",SZ(res),an);
    REP(i,SZ(res))printf("%d %d\n",res[i].F,res[i].S);
    return 0;
}