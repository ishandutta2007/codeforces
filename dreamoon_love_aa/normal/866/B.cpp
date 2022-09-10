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
int a[SIZE],b[SIZE],s[SIZE];
LL solve(VPII& aa,LL a_n,LL b_n,int S,LL need){
    sort(ALL(aa));
    int it=0;
    LL v=0;
    while(1){
        a_n++;b_n--;
        v+=aa[it].F;
        aa[it].S--;
        if(!aa[it].S)it++;
        if((b_n+S-1)/S+(a_n+S-1)/S==need)return v;
    };
    return -1;
}
int main(){
    DRII(N,S);
    LL sum_s=0;
    REP(i,N){
        RIII(s[i],a[i],b[i]);
        sum_s+=s[i];
    }
    LL need=(sum_s+S-1)/S;
    LL a_n=0,b_n=0;
    LL v=0;
    VPII bb,aa;
    REP(i,N){
        if(a[i]<=b[i]){
            b_n+=s[i];
            v+=(LL)b[i]*s[i];
            aa.PB(MP(b[i]-a[i],s[i]));
        }
        else{
            a_n+=s[i];
            v+=(LL)a[i]*s[i];
            bb.PB(MP(a[i]-b[i],s[i]));
        }
    }
    if((b_n+S-1)/S+(a_n+S-1)/S==need)return 0*printf("%lld\n",v);
    printf("%lld\n",v-min(solve(aa,a_n,b_n,S,need),solve(bb,b_n,a_n,S,need)));
    return 0;
}