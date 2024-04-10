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
#define FN 500010
#define FM 4200010
#define INF 1034567890
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
bool check(int st,int from[],int to[]){
    int now=st;
    int now_used=to[0]-now;
    now-=now_used;
    if(now_used<0)return 0;
    REPP(j,1,40){
        if(to[j]>now+now_used){
            int tmp=to[j]-now-now_used;
            if(tmp>now)return 0;
            now-=tmp;
            now_used+=tmp;
        }
        else{
            if(to[j]>=now){
                now_used=to[j]-now;
            }
            else{
                now=to[j];
                now_used=0;
            }
        }
        now-=from[j];
        now_used+=from[j];
        if(now<0)return 0;
    }
    return 1;
}
int main(){
    DRI(n);
    int to[44]={},from[44]={};
    int pp=0;
    REP(i,n){
        LL x;
        scanf("%I64d",&x);
        while((1LL<<pp)<x)pp++;
        if((1LL<<pp)==x){
            to[pp]++;
        }
        else from[pp-1]++;
    }
    VI an;
    REPP(i,1,to[0]+1){
        if(check(i,from,to))an.PB(i);
    }
    if(SZ(an)==0)puts("-1");
    else{
        REP(i,SZ(an))printf("%d%c",an[i]," \n"[i==SZ(an)-1]);
    }
    return 0;
}