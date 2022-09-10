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
char s[SIZE];
int d[SIZE],dn;
int r[SIZE],rn;
bool valid(int L,int R,int x,int m){
    if(R<x)return x-L<=m;
    if(L>x)return R-x<=m;
    return R-L+min(x-L,R-x)<=m;
}
bool good(int m){
    int it=0;
    REP(i,rn){
        if(abs(d[it]-r[i])>m)continue;
        int it2=it+1;
        while(it2<dn&&valid(d[it],d[it2],r[i],m))it2++;
        it=it2;
        if(it==dn)return 1;
    }
    return 0;
}
int main(){
    DRI(n);
    RS(s);
    REP(i,n){
        if(s[i]=='*')d[dn++]=i;
        else if(s[i]=='P')r[rn++]=i;
    }
    int ll=1,rr=n*2;
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(good(mm))rr=mm;
        else ll=mm+1;
    }
    printf("%d",ll);
    return 0;
}