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
void print_array(int arr[],int n){
    REP(i,n){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int an[SIZE],a[SIZE],sn;
PII stk[SIZE];
int main(){
    DRII(n,m);
    REP(i,n)RI(a[i]);
    REP(i,m){
        DRII(x,y);
        while(sn&&y>=stk[sn-1].S)sn--;
        stk[sn++]=MP(x,y);
    }
    REPP(i,stk[0].S,n)an[i]=a[i];
    sort(a,a+stk[0].S);
    int ll=0,rr=stk[0].S;
    int it=stk[0].S;
    REPP(i,1,sn){
        if(stk[i-1].F==1){
            REP(j,stk[i-1].S-stk[i].S)an[--it]=a[--rr];
        }
        else{
            REP(j,stk[i-1].S-stk[i].S)an[--it]=a[ll++];
        }
    }
    if(stk[sn-1].F==1) REPP(i,ll,rr)an[i-ll]=a[i];
    else REPP(i,ll,rr)an[i-ll]=a[rr-(i-ll)-1];
    print_array(an,n);
    return 0;
}