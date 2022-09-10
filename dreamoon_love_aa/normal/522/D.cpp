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
// template end here
int a[SIZE];
map<int,int>H;
PII pp[SIZE];
int pn;
int BIT[SIZE];
void ins(int x,int v){
    for(;x<SIZE;x+=x&-x)BIT[x]=min(BIT[x],v);
}
int qqq(int x){
    int res=MOD;
    for(;x;x-=x&-x)res=min(res,BIT[x]);
    return res;
}
VPII qq[SIZE];
int an[SIZE];
int main(){
    memset(BIT,0x7777,sizeof(BIT));
    DRII(n,Q);
    REP(i,n)RI(a[i+1]);
    REPP(i,1,n+1){
        if(H.count(a[i]))pp[pn++]=MP(H[a[i]],i);
        H[a[i]]=i;
    }
    sort(pp,pp+pn);
    reverse(pp,pp+pn);
    REP(k,Q){
        DRII(x,y);
        qq[x].PB(MP(y,k));
    }
    int it=0;
    for(int k=n;k;k--){
        while(it<pn&&pp[it].F==k){
            ins(pp[it].S,pp[it].S-pp[it].F);
            it++;
        }
        REP(i,SZ(qq[k])){
            an[qq[k][i].S]=qqq(qq[k][i].F);
        }
    }
    REP(i,Q)printf("%d\n",an[i]>=n?-1:an[i]);
    return 0;
}