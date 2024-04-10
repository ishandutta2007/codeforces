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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
int d[SIZE],a[SIZE];
int BIT[SIZE];
void ins(int x,int v=1){
    x++;
    for(;x<SIZE;x+=x&-x)BIT[x]+=v;
}
int qq(int x){
    x++;
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
int main(){
    DRI(n);
    REP(i,n){
        DRI(x);
        int low=x-qq(x);
        ins(x);
        d[n-i-1]+=low;
    }
    MS0(BIT);
    REP(i,n){
        DRI(x);
        int low=x-qq(x);
        ins(x);
        d[n-i-1]+=low;
    }
    REP(i,n){
        d[i+1]+=d[i]/(i+1);
        d[i]%=(i+1);
    }
    MS0(BIT);
    REP(i,n)ins(i);
    for(int i=n-1;i>=0;i--){
        int need=d[i]+1;
        int ll=0,rr=n-1;
        while(ll<rr){
            int mm=(ll+rr)>>1;
            int v=qq(mm);
            if(v>=need)rr=mm;
            else ll=mm+1;
        }
        if(i!=n-1)printf(" ");
        printf("%d",ll);
        ins(ll,-1);
    }
    puts("");
    return 0;
}