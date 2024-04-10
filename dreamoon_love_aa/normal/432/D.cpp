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
char s[SIZE];
int far[SIZE];
void Z(char str[],int n){
    int ll=0,rr=0;
    REPP(i,1,n){
        int len=0;
        if(i<rr)len=min(far[i-ll],rr-i);
        while(i+len<n&&s[len]==s[i+len])len++;
        far[i]=len;
        if(i+len>rr){
            ll=i;
            rr=i+len;
        }
    }
}
int main(){
    RS(s);
    int n=LEN(s);
    Z(s,n);
    VI d;
    REPP(i,1,n+1)
        if(far[i])d.PB(far[i]);
    sort(ALL(d));
    VPII an;
    REPP(i,1,n){
        if(far[n-i]>=i){
            int num=1+d.end()-lower_bound(ALL(d),i);
            an.PB(MP(i,num));
        }
    }
    an.PB(MP(n,1));
    printf("%d\n",SZ(an));
    REP(i,SZ(an))printf("%d %d\n",an[i].F,an[i].S);
    return 0;
}